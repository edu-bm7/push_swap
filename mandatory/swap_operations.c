#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->a_top < 1)
		return ;
	temp = stacks->a_stack[stacks->a_top];
	stacks->a_stack[stacks->a_top] = stacks->a_stack[stacks->a_top - 1];
	stacks->a_stack[stacks->a_top - 1] = temp;
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->b_top < 1)
		return ;
	temp = stacks->b_stack[stacks->b_top];
	stacks->b_stack[stacks->b_top] = stacks->b_stack[stacks->b_top - 1];
	stacks->b_stack[stacks->b_top - 1] = temp;
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	int	temp_a;
	int	temp_b;

	if (stacks->a_top < 1)
		return ;
	if (stacks->b_top < 1)
		return ;
	temp_a = stacks->a_stack[stacks->a_top];
	temp_b = stacks->b_stack[stacks->b_top];
	stacks->a_stack[stacks->a_top] = stacks->a_stack[stacks->a_top - 1];
	stacks->a_stack[stacks->a_top - 1] = temp_a;
	stacks->b_stack[stacks->b_top] = stacks->b_stack[stacks->b_top - 1];
	stacks->b_stack[stacks->b_top - 1] = temp_b;
	ft_printf("ss\n");
}
