//
// Created by pedro on 02/11/22.
//
#include "types.h"
#include "instruction.h"
#include "cpu.h"
#include "instruction_decoder.h"
#include <stdbool.h>
#include "memory.h"

void decode_one_word_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction->content.kind_one_word.word = pop_memory_word(program_memory, &cpu->instruction);

}
void decode_one_register_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction->content.kind_one_register.register_ = pop_memory_byte(program_memory, &cpu->instruction);

}
void decode_two_registers_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction->content.kind_two_registers.register1 = pop_memory_byte(program_memory, &cpu->instruction);
    instruction->content.kind_two_registers.register2 = pop_memory_byte(program_memory, &cpu->instruction);
}
void decode_one_word_one_register_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction->content.kind_one_word_one_register.word = pop_memory_word(program_memory, &cpu->instruction);
    instruction->content.kind_one_word_one_register.register_= pop_memory_byte(program_memory, &cpu->instruction);
}

void decode_interrupt_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction->content.kind_interrupt.interrupt = pop_memory_byte(program_memory, &cpu->instruction);
}
void decode_one_pointer_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction->content.kind_one_pointer.pointer = pop_memory_word(program_memory, &cpu->instruction);
}
void decode_one_word_one_pointer_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction->content.kind_one_word_one_pointer.word = pop_memory_word(program_memory, &cpu->instruction);
    instruction->content.kind_one_word_one_pointer.pointer = pop_memory_word(program_memory, &cpu->instruction);
}

void decode_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    instruction_code_t instruction_code = pop_memory_byte(program_memory, &cpu->instruction);
    instruction->code=instruction_code;
    switch (instruction_code) {
        case halt:
            break;
        case mov:
            decode_two_registers_instruction(instruction, cpu, program_memory); break;
        case load:
            decode_one_word_one_register_instruction(instruction, cpu, program_memory); break;
        case interrupt:
            decode_interrupt_instruction(instruction, cpu, program_memory); break;
        case equals:
        case cmp:
            decode_two_registers_instruction(instruction, cpu, program_memory); break;
        case jump:
        case jump_eq:
        case jump_neq:
        case jump_z:
        case jump_nz:
        case jump_c:
        case jump_nc:
        case jump_s:
            decode_one_pointer_instruction(instruction, cpu, program_memory); break;
        case push_r:
            decode_one_register_instruction(instruction, cpu, program_memory); break;
        case push_v:
            decode_one_word_instruction(instruction, cpu, program_memory); break;
        case pop:
            decode_one_register_instruction(instruction, cpu, program_memory); break;
        case read_:
        case write_:
            decode_one_word_one_pointer_instruction(instruction, cpu, program_memory); break;
        case add:
        case sub:
            decode_two_registers_instruction(instruction, cpu, program_memory); break;
        case inc:
        case dec:
            decode_one_register_instruction(instruction, cpu, program_memory); break;
        default:
            cpu->segfault=true;
    }

}