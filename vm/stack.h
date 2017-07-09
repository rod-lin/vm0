#ifndef VM0_VM_STACK_H
#define VM0_VM_STACK_H

#include "std/base.h"

#include "vm/value.h"

typedef struct {
	vm0_value_t *bottom;
	vm0_value_t *top;
	vm0_value_t *edge;
	std_size_t size;
} vm0_stack_t;

void
vm0_stack_init(vm0_stack_t *stack, std_size_t init);

void
vm0_stack_clean(vm0_stack_t *stack);

#define _vm0_stack_size(stack) ((stack)->size)

STD_INLINE
std_bool_t
_vm0_stack_full(vm0_stack_t *stack)
//@ pre stack != STD_NULL;
{
	return stack->top == stack->edge;
}

STD_INLINE
void
_vm0_stack_expand(vm0_stack_t *stack)
{
	std_size_t top = std_ptrdiff(stack->top, stack->bottom, sizeof(*stack->bottom));
	stack->size <<= 1;
	stack->bottom = std_srrealloc(stack->bottom, sizeof(*stack->bottom) * stack->size);
	stack->top = stack->bottom + top;
	stack->edge = stack->bottom + stack->size;
}

STD_INLINE
void
vm0_stack_push(vm0_stack_t *stack, vm0_value_t val)
//@ pre stack != STD_NULL;
{
	if (_vm0_stack_full(stack))
		_vm0_stack_expand(stack);

	*(stack->top++) = val;
}

STD_INLINE
vm0_value_t
vm0_stack_pop(vm0_stack_t *stack)
//@ pre stack != STD_NULL;
{
	std_assert(stack->top != stack->bottom, "pop empty stack");
	return *(--stack->top);
}

#endif
