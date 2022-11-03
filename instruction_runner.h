//
// Created by pedro on 02/11/22.
//

#ifndef INSTRUCTION_RUNNER_H
#define INSTRUCTION_RUNNER_H

#include "memory.h"
#include "instruction.h"
#include "cpu.h"

bool run_instruction(instruction* instruction, cpu* cpu, memory* program_memory);
#endif //INSTRUCTION_RUNNER_H
