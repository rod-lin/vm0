#ifndef VM0_VM_INSTR_H
#define VM0_VM_INSTR_H

#include "std/base.h"

typedef struct {
    std_byte_t opc;
    std_byte_t pad;

    union {
        std_byte_t b
        std_int16_t s;
    } opr;
} vm0_instr_t;

#endif
