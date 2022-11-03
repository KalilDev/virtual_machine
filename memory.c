//
// Created by pedro on 02/11/22.
//
#include "memory.h"

word_t deref_memory_word(memory memory_content, pointer_t pointer) {
    word_t word = 0;
    memory it = memory_content+pointer;
    for (int offset = 6; offset >= 0; offset-=2, it++) {
        word |= *it << offset;
    }
    return word;
}
void write_memory_word(word_t word,memory memory_content, pointer_t pointer) {
    memory it = memory_content+pointer;
    for (int offset = 6; offset>=0; offset-=2, it++) {
        *it = (word >> offset) & 0xFF;
    }
}
byte deref_memory_byte(memory memory, pointer_t pointer) {
    return memory[pointer];
}
void write_memory_byte(byte byte,memory memory_content, pointer_t pointer) {
    memory_content[pointer] = byte;
}
word_t pop_memory_word(memory* memory, pointer_t *pointer) {
    word_t word = deref_memory_word(*memory, *pointer);
    *pointer+=sizeof(word_t);
    return word;
}

byte pop_memory_byte(memory* memory, pointer_t *pointer) {
    byte byte = deref_memory_byte(*memory, *pointer);
    *pointer+=1;
    return byte;
}