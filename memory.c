//
// Created by pedro on 02/11/22.
//
#include "memory.h"

word_t deref_memory_word(memory memory_content, pointer_t pointer) {
    word_t word = 0;
    word |= memory_content[pointer + 0] << 24;
    word |= memory_content[pointer + 1] << 16;
    word |= memory_content[pointer + 2] << 8;
    word |= memory_content[pointer + 3] << 0;
    return word;
}
void write_memory_word(word_t word,memory memory_content, pointer_t pointer) {
    memory_content[pointer + 0] = word & 0xFF000000 >> 24;
    memory_content[pointer + 1] = word & 0x00FF0000 >> 16;
    memory_content[pointer + 2] = word & 0x0000FF00 >> 8;
    memory_content[pointer + 3] = word & 0x000000FF >> 0;
}
byte deref_memory_byte(memory memory, pointer_t pointer) {
    return memory[pointer];
}
void write_memory_byte(byte byte,memory memory_content, pointer_t pointer) {
    memory_content[pointer] = byte;
}
word_t pop_memory_word(memory memory, pointer_t *pointer) {
    word_t word = deref_memory_word(memory, *pointer);
    *pointer+=sizeof(word_t);
    return word;
}

byte pop_memory_byte(memory memory, pointer_t *pointer) {
    byte byte = deref_memory_byte(memory, *pointer);
    *pointer+=1;
    return byte;
}