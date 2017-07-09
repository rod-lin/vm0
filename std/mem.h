#ifndef VM0_STD_MEM_H
#define VM0_STD_MEM_H

#include <stdlib.h>
#include <string.h>

#include "std/type.h"
#include "std/com.h"
#include "std/dbg.h"

// r -> raw, s -> save
#define std_rfree(ptr) free(ptr)

STD_INLINE
void *
std_ralloc(std_size_t size)
{
    return size ? malloc(size) : STD_NULL;
}

#define std_bzero(ptr, size) memset((ptr), 0, (size));

STD_INLINE
void *
std_sralloc(std_size_t size)
//@ post \result != STD_NULL;
{
    void *ptr = std_ralloc(size);
    std_assert(ptr, "failed to allocate");
    return ptr;
}

STD_INLINE
void *
std_sralloc_init(std_size_t size)
//@ post \result != STD_NULL;
{
    void *ptr = std_sralloc(size);
    std_bzero(ptr, size);
    return ptr;
}

STD_INLINE
void *
std_rrealloc(void *orig, std_size_t size)
{
    return size ? realloc(orig, size) : STD_NULL;
}

STD_INLINE
void *
std_srrealloc(void *orig, std_size_t size)
{
    void *ptr = std_rrealloc(orig, size);
    std_assert(ptr, "failed to reallocate");
    return ptr;
}

#endif
