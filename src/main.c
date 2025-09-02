#include "alloc.h"
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 1024

int main() {
  /*
   * mmap example
   */
  // void* memory_block;

  // memory_block = mmap(NULL,
  //                     BLOCK_SIZE,
  //                     PROT_READ | PROT_WRITE,
  //                     MAP_PRIVATE | MAP_ANONYMOUS,
  //                     -1,
  //                     0);

  // if (memory_block == MAP_FAILED) {
  //   perror("mmap failed.");
  //   return EXIT_FAILURE;
  // }
  // 
  // printf("Allocated a %d-byte memory block at address: %p\n", BLOCK_SIZE, memory_block);
  // 
  // memset(memory_block, '\0', BLOCK_SIZE*sizeof(char));

  // char* payload = (char *)memory_block;
  // strcpy(payload, "The contents of my first mmap block!");

  // printf("Content of the memory block: %s\n", payload);

  // if (munmap(memory_block, BLOCK_SIZE) == -1) {
  //   perror("munmap failed");
  //   return EXIT_FAILURE;
  // }

  // printf("Content of the memory block at %p has been unmapped.\n", memory_block);

  const size_t STRING_LENGTH = 20;
  char* str;
  if ((str = (char*) my_malloc(STRING_LENGTH * sizeof(char))) == NULL) {
    printf("String could not be allocated.");
    return -1;
  }

  printf("String allocated successfully.\n");

  strcpy(str, "Hello from the first block!\n");
  printf("%s", str);

  my_free(str);
  printf("First block freed.\n");

  return 0;
}
