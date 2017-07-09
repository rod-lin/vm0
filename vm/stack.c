#include "std/base.h"

#include "vm/stack.h"

void
vm0_stack_init(vm0_stack_t *stack, std_size_t init)
//@ pre stack != STD_NULL
{
	stack->top = stack->bottom = std_sralloc(sizeof(*stack->bottom) * init);
	stack->edge = stack->bottom + init;
	stack->size = init;
}

void
vm0_stack_clean(vm0_stack_t *stack)
{
	std_rfree(stack->bottom);
}
