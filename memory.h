//
// Created by pedro on 02/11/22.
//

#ifndef MEMORY_H
#define MEMORY_H
#include "types.h"

typedef byte *memory;
#define INITIAL_MEMORY_SIZE 128
word_t deref_memory_word(memory memory, pointer_t pointer);
void write_memory_word(word_t word,memory memory, pointer_t pointer);
byte deref_memory_byte(memory memory, pointer_t pointer);
void write_memory_byte(byte byte,memory memory_content, pointer_t pointer);
word_t pop_memory_word(memory memory, pointer_t *pointer);
byte pop_memory_byte(memory memory, pointer_t *pointer);

#endif //MEMORY_H
