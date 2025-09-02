#ifndef ALLOC_H
#define ALLOC_H

#include <stddef.h>

// No need to store size: blocks are contiguous
typedef struct header {
  struct header* next;
  struct header* prev;
  unsigned char is_free;
  size_t size;
} header_t;

void* my_malloc(size_t size);
void my_free(void* block);

#endif // !ALLOC_H
