#include "alloc.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>

void* my_malloc(const size_t size) {
  static header_t* head = NULL;
  static const size_t header_size = sizeof(header_t);
  //TODO: Could keep track of the min/max block size available from previous searches to speed up allocation?

  // Initialise the head block
  if (head == NULL) {
    const int page_size = getpagesize();

    head = (header_t*) sbrk(page_size);
    head->is_free = 1;
    head->next = NULL;
    head->prev = NULL;
    head->size = page_size - header_size;
  }

  // locate block of sufficient size
  header_t* target = head;
  while (!target->is_free || target->size < size) {
    if (target->next == NULL) return NULL;
    target = target->next;
  }
  target->is_free = 0;

  // Split the block, if possible
  if (target->size - size > header_size) {
    header_t* new_block = target + header_size + size;
    new_block->is_free = 1;

    new_block->next = target->next;
    new_block->prev = target;

    target->next = new_block;
    
    new_block->size = target->size - size - header_size;
    target->size = size;
  }
  
  return target + header_size;
}

void my_free(void* block) {
  header_t* target = block - sizeof(header_t);
  target->is_free = 1;

  while (target->prev != NULL && target->prev->is_free) target = target->prev;

  while (target->next != NULL && target->next->is_free) {
    target->size = target->next->size + sizeof(header_t);
    target->next = target->next->next;
  }
}
