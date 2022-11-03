//
// Created by pedro on 02/11/22.
//
#include "types.h"
#include "instruction.h"
#include "cpu.h"
#include "memory.h"
#include "instruction_runner.h"
#include <stdbool.h>

bool run_instruction(instruction* instruction, cpu* cpu, memory* program_memory) {
    // the stack register is the first register, the other ones can be acessed as if they were an register_t[8]
    vm_register_t *registers = &cpu->stack;
    union instruction_content i = instruction->content;
    switch (instruction->code) {
        case halt: return 1; break;
        case mov:
            registers[i.mov.to] = registers[i.mov.from];
            break;
        case load:
            registers[i.load.to] = i.load.word;
            break;
        case interrupt:
            cpu->instruction = cpu->interrupt_table[i.interrupt.code];
            break;
        case equals:
            break;
        case cmp:
            break;
        case jump:
            cpu->instruction = i.jump.location;
            break;
        case jump_eq:
            break;
        case jump_neq:
            break;
        case jump_z:
            if (!cpu->zero) {
                break;
            }
            cpu->instruction = i.jump_z.location;
            break;
        case jump_nz:
            if (cpu->zero) {
                break;
            }
            cpu->instruction = i.jump_z.location;
            break;
        case jump_c:
            break;
        case jump_nc:
            break;
        case jump_s:
            break;
        case push_r:
            break;
        case push_v:
            break;
        case pop:
            break;
        case read_:
            registers[i.read.reg] = deref_memory_word(*program_memory, i.read.location);
            break;
        case write_:
            write_memory_word(registers[i.write.reg],program_memory, i.write.location);
            break;
        case add: {
            word_t a =registers[i.add.a];
            word_t b =registers[i.add.b];
            registers[i.add.a]= a + b;
            if (registers[i.add.a] == 0) {
                cpu->zero=true;
            }
            if (a + b < a) {
                cpu->carry=1;
            }
            break;
        }
        case sub:
            registers[i.sub.a]-=registers[i.sub.b];
            if (registers[i.sub.a] == 0) {
                cpu->zero=true;
            }
            break;
        case inc:
            break;
        case dec:
            break;
    }
}