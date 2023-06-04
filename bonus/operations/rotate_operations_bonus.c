#include "push_swap_bonus.h"

void	ra(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->next;
}

void	rb(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->next;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
