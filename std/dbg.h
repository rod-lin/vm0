#ifndef VM0_STD_DBG_H
#define VM0_STD_DBG_H

#include <stdio.h>
#include <stdlib.h>

#define std_trace(...) \
    { \
        fprintf(stderr, "vm0 trace: %s: %d: ", __FILE__, __LINE__); \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, "\n"); \
    }

#define std_assert(cond, ...) \
    if (!(cond)) { \
        std_trace(__VA_ARGS__); \
        std_abort(); \
    }

#define std_abort() abort()

#endif
