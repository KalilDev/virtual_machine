#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include"cpu.h"
#include "instruction.h"
#include "memory.h"
#include "instruction_decoder.h"
#include "instruction_runner.h"
#include "assert.h"
#include <unistd.h>

void load_program(memory* program_memory,size_t *memory_size) {
    FILE *program = fopen("../program.vm", "r");
    if (program == NULL) {
        perror("fopen failed");
        exit(1);
    }
    size_t used_memory_size = 0;
    *memory_size = INITIAL_MEMORY_SIZE;
    *program_memory = malloc(*memory_size);

    for (int ch = fgetc(program); ch != EOF; ch = fgetc(program), used_memory_size++) {
        if (*memory_size + 1 <= used_memory_size ) {
            size_t new_memory_size = 2 * used_memory_size;
            *program_memory = realloc(*program_memory, new_memory_size);
        }
        (*program_memory)[used_memory_size] = (char)ch;
    }
    fclose(program);
}

void write_memory(memory program_memory, size_t used_memory_size) {
    FILE *out = fopen("program.out", "w");
    fwrite(program_memory,sizeof(byte),used_memory_size,out);
    fclose(out);
}

void print_cpu(cpu * cpu) {
    printf("INSTRUCTION: 0x%08x\n", cpu->instruction);
    printf("STACK: 0x%08x R0 0x%08x\n",cpu->stack, cpu->registers[0]);
    printf("   R1: 0x%08x R2 0x%08x\n",cpu->registers[1], cpu->registers[2]);
    printf("   R3: 0x%08x R4 0x%08x\n",cpu->registers[3], cpu->registers[4]);
    printf("   R5: 0x%08x R6 0x%08x\n",cpu->registers[5], cpu->registers[6]);
    printf("CARRY: %u, OVERFLOW: %u\n", cpu->carry, cpu->overflow);
    printf("ZERO: %u, NEGATE: %u\n", cpu->zero, cpu->negate);
    printf("SEGFAULT: %u\n", cpu->segfault);
}

int main() {
    assert(sizeof(instruction_code_t) == sizeof(byte));
    memory program_memory = NULL;
    size_t memory_size = 0;
    load_program(&program_memory, &memory_size);
    cpu cpu = {0};
    while(true) {
        print_cpu(&cpu);
        instruction instruction;
        decode_instruction(&instruction, &cpu, &program_memory);
        if (cpu.segfault) {
            break;
        }
        bool halted = !run_instruction(&instruction, &cpu, &program_memory);
        if (halted || cpu.segfault) {
            break;
        }
        // no halt
        if (cpu.instruction == memory_size) {
            cpu.segfault = true;
            break;
        }
    };
    if (cpu.segfault) {
        printf("SEGFAULT:\n\n");
    }
    print_cpu(&cpu);
    write_memory(program_memory, memory_size);
    free(program_memory);
}
