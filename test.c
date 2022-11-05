//
// Created by pedro on 04/11/22.
//
#include <stdio.h>
#include <stdbool.h>
#include "instruction_decoder.h"
#include "test.h"

bool deref_memory_word_test() {
    pointer_t pointer = 0;
    byte program_memory[] = {
            0xDE,
            0xAD,
            0xBE,
            0xEF
    };
    return deref_memory_word(program_memory, pointer) == 0xDEADBEEF;
}
bool deref_memory_byte_test() {
    pointer_t pointer = 0;
    byte program_memory[] = {
            0xFF,
    };
    return deref_memory_byte(program_memory, pointer) == 0xFF;
}
bool pop_memory_word_test() {
    pointer_t pointer = 0;
    byte program_memory[] = {
            0xDE,
            0xAD,
            0xBE,
            0xEF
    };
    return pop_memory_word(program_memory, &pointer) == 0xDEADBEEF &&
           pointer == sizeof(word_t);
}
bool pop_memory_byte_test() {
    pointer_t pointer = 0;
    byte program_memory[] = {
            0xFF,
    };
    return pop_memory_byte(program_memory, &pointer) == 0xFF &&
           pointer == sizeof(byte);
}
bool decode_one_word_instruction_test() {
    instruction instruction = {0};
    cpu cpu = {.instruction=1};
    byte program_memory[] = {
            0x00,
            0xDE,
            0xAD,
            0xBE,
            0xEF
    };
    decode_one_word_instruction(&instruction, &cpu, program_memory);
    return instruction.content.kind_one_word.word == 0xDEADBEEF;
}
bool decode_one_register_instruction_test() {
    instruction instruction = {0};
    cpu cpu = {.instruction=1};
    byte program_memory[] = {
            0x00,
            0xDE,
    };
    decode_one_register_instruction(&instruction, &cpu, program_memory);
    return instruction.content.kind_one_register.register_ == 0xDE;
}
bool decode_two_registers_instruction_test() {
    instruction instruction = {0};
    cpu cpu = {.instruction=1};
    byte program_memory[] = {
            0x00,
            0xDE,
            0xAD,
    };
    decode_two_registers_instruction(&instruction, &cpu, program_memory);
    return instruction.content.kind_two_registers.register1 == 0xDE &&
           instruction.content.kind_two_registers.register2 == 0xAD;
}
bool decode_one_word_one_register_instruction_test() {
    instruction instruction = {0};
    cpu cpu = {.instruction=1};
    byte program_memory[] = {
            0x00,
            0xDE,
            0xAD,
            0xBE,
            0xEF,
            0xFF,
    };
    decode_one_word_one_register_instruction(&instruction, &cpu, program_memory);
    return instruction.content.kind_one_word_one_register.word == 0xDEADBEEF &&
           instruction.content.kind_one_word_one_register.register_ == 0xFF;
}
bool decode_interrupt_instruction_test() {
    instruction instruction = {0};
    cpu cpu = {.instruction=1};
    byte program_memory[] = {
            0x00,
            0xFF,
    };
    decode_interrupt_instruction(&instruction, &cpu, program_memory);
    return instruction.content.kind_interrupt.interrupt == 0xFF;
}
bool decode_one_pointer_instruction_test() {
    instruction instruction = {0};
    cpu cpu = {.instruction=1};
    byte program_memory[] = {
            0x00,
            0xDE,
            0xAD,
            0xBE,
            0xEF,
    };
    decode_one_pointer_instruction(&instruction, &cpu, program_memory);
    return instruction.content.kind_one_pointer.pointer == 0xDEADBEEF;
}
bool decode_one_word_one_pointer_instruction_test() {
    instruction instruction = {0};
    cpu cpu = {.instruction=1};
    byte program_memory[] = {
            0x00,
            0xDE,
            0xAD,
            0xBE,
            0xEF,
            0xBE,
            0xEF,
            0xDE,
            0xAD,
    };
    decode_one_word_one_pointer_instruction(&instruction, &cpu, program_memory);
    return instruction.content.kind_one_word_one_pointer.word == 0xDEADBEEF &&
            instruction.content.kind_one_word_one_pointer.pointer == 0xBEEFDEAD;
}

static const struct test tests[] = {
        TEST(deref_memory_word),
        TEST(deref_memory_byte),
        TEST(pop_memory_word),
        TEST(pop_memory_byte),
        TEST(decode_one_word_instruction),
        TEST(decode_one_register_instruction),
        TEST(decode_two_registers_instruction),
        TEST(decode_one_word_one_register_instruction),
        TEST(decode_interrupt_instruction),
        TEST(decode_one_pointer_instruction),
        TEST(decode_one_word_one_pointer_instruction),
        {NULL, NULL}
};

int main() {
    run_tests(tests);
}