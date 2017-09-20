/*******************************************************************************
 *
 * - Bloom filter to determine if a user has entered a word or not
 *
 ******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

/* implementation of djb2 */
uint64_t hash(char *str) {
  uint64_t hash = 5381;
  int64_t c;
  while ((c = *str++)) {
    hash = ((hash << 5 ) + hash) + c; /* hash * 33 + c */
  }
  return hash;
}

#define MAX_DICT_SIZE 1024

int main(int argc, char** argv) {
  char *buffer;
  size_t bufsize = 32;
  size_t characters;
  buffer = (char *) calloc(bufsize * sizeof(char), 0);
  if (buffer == NULL) {
    perror("Unable to allocate buffer\n");
    exit(EXIT_FAILURE);
  }

  int offset = -1;


  uint32_t dictionary[1024] = {0};
  uint64_t hash_key = 0;
  while(offset != 0) {
    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);
    hash_key = hash(buffer)%MAX_DICT_SIZE;
    offset = strncmp(buffer,"Q\n",bufsize);

    if (characters == 0) break;

    if (dictionary[hash_key]) {
      printf("I know this word\n");
    } else {
      printf("%s is a new word\n", buffer);
      dictionary[hash_key]++;
    }
  }

  printf("Goodbye!\n");

}
