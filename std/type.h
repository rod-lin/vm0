#ifndef VM0_STD_TYPE_H
#define VM0_STD_TYPE_H

#include <stdint.h>

typedef int8_t			std_int8_t;
typedef int16_t			std_int16_t;
typedef int32_t			std_int32_t;
typedef int64_t			std_int64_t;

typedef uint8_t			std_uint8_t;
typedef uint16_t		std_uint16_t;
typedef uint32_t		std_uint32_t;
typedef uint64_t		std_uint64_t;

typedef intptr_t		std_ptr_t;
typedef uintptr_t		std_uptr_t;

typedef std_uint8_t		std_byte_t;
typedef std_uint8_t		std_bool_t;
typedef std_uptr_t		std_size_t;

#define STD_NULL ((void *)0)

#endif
