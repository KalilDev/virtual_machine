//
// Created by pedro on 02/11/22.
//

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "types.h"

typedef  enum  __attribute__ ((__packed__)) {
    halt,
    mov,
    load,
    interrupt,
    equals,
    cmp,
    jump,
    jump_eq,
    jump_neq,
    jump_z,
    jump_nz,
    jump_c,
    jump_nc,
    jump_s,
    push_r,
    push_v,
    pop,
    read_,
    write_,
    add,
    sub,
    inc,
    dec,
} instruction_code_t;

typedef struct {
    instruction_code_t code;
    union instruction_content {
#include "decode_instruction_kinds.h"
        struct {
        } halt;
        struct {
            register_id from, to;
        } mov;
        struct {
            word_t word;
            register_id to;
        } load;
        struct {
            interrupt_id code;
        } interrupt;
        struct {
            register_id a, b;
        } equals;
        struct {
            register_id a, b;
        } cmp;
        struct {
            pointer_t location;
        } jump;
        struct {
            pointer_t location;
        } jump_eq;
        struct {
            pointer_t location;
        } jump_neq;
        struct {
            pointer_t location;
        } jump_z;
        struct {
            pointer_t location;
        } jump_nz;
        struct {
            pointer_t location;
        } jump_c;
        struct {
            pointer_t location;
        } jump_nc;
        struct {
            pointer_t location;
        } jump_s;
        struct {
            register_id reg;
        } push_r;
        struct {
            word_t value;
        } push_v;
        struct {
            register_id reg;
        } pop;
        struct {
            register_id reg;
            pointer_t location;
        } read;
        struct {
            register_id reg;
            pointer_t location;
        } write;
        struct {
            register_id a, b;
        } add;
        struct {
            register_id a, b;
        } sub;
        struct {
            register_id register_;
        } inc;
        struct {
            register_id register_;
        } dec;
    } content;
} instruction;

#endif //INSTRUCTION_H
