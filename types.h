//
// Created by pedro on 02/11/22.
//

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef unsigned char byte;
typedef byte register_id;
typedef byte interrupt_id;
typedef uint32_t word_t;

typedef word_t vm_register_t;
typedef word_t pointer_t;

typedef bool flag_t;
#endif //TYPES_H
