#include "push_swap_bonus.h"

void	rra(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->previous;
}

void	rrb(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->previous;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
