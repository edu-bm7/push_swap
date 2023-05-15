#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	if (is_empty(stacks->b_top) || is_full(stacks->a_top, stacks->size))
		return ;
	stacks->a_top++;
	stacks->a_stack[stacks->a_top] = stacks->b_stack[stacks->b_top];
	stacks->b_top--;
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{
	if (is_empty(stacks->a_top) || is_full(stacks->b_top, stacks->size))
		return ;
	stacks->b_top++;
	stacks->b_stack[stacks->b_top] = stacks->a_stack[stacks->a_top];
	stacks->a_top--;
	ft_printf("pb\n");
}
