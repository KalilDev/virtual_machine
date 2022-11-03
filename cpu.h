//
// Created by pedro on 02/11/22.
//

#ifndef CPU_H
#define CPU_H

#include "types.h"

typedef struct {
    pointer_t instruction;
    vm_register_t stack;
    vm_register_t registers[7];
    flag_t carry, overflow, zero, negate, segfault;
    pointer_t interrupt_table[256];
} cpu;
#endif //CPU_H
