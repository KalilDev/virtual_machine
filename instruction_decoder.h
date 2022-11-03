//
// Created by pedro on 02/11/22.
//

#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#include "memory.h"
#include "cpu.h"

void decode_one_word_instruction(instruction* instruction, cpu* cpu, memory* program_memory);
void decode_one_register_instruction(instruction* instruction, cpu* cpu, memory* program_memory);
void decode_two_registers_instruction(instruction* instruction, cpu* cpu, memory* program_memory);
void decode_one_word_one_register_instruction(instruction* instruction, cpu* cpu, memory* program_memory);
void decode_interrupt_instruction(instruction* instruction, cpu* cpu, memory* program_memory);
void decode_one_pointer_instruction(instruction* instruction, cpu* cpu, memory* program_memory);
void decode_one_word_one_pointer_instruction(instruction* instruction, cpu* cpu, memory* program_memory);

void decode_instruction(instruction* instruction, cpu* cpu, memory* program_memory);

#endif //INSTRUCTION_DECODER_H
