#include <stdlib.h>

// r -> raw
#define vm0_ralloc(size) malloc(size)
#define vm0_ralloc_init(size) calloc(1, (size))
#define vm0_rfree(ptr) free(ptr)
