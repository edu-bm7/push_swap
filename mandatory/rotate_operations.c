#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	int i;
	int	temp;

	i = stacks->a_top;
	temp = stacks->a_stack[stacks->a_top];
	while (i)
	{
		stacks->a_stack[i] = stacks->a_stack[i - 1];
		i--;
	}
	stacks->a_stack[0] = temp;
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	int i;
	int	temp;

	i = stacks->b_top;
	temp = stacks->b_stack[stacks->b_top];
	while (i)
	{
		stacks->b_stack[i] = stacks->b_stack[i - 1];
		i--;
	}
	stacks->b_stack[0] = temp;
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	int index_a;
	int	temp_a;
	int index_b;
	int temp_b;

	index_b = stacks->b_top;
	temp_b = stacks->b_stack[stacks->b_top];
	index_a = stacks->a_top;
	temp_a = stacks->a_stack[stacks->a_top];
	while (index_a)
	{
		stacks->a_stack[index_a] = stacks->a_stack[index_a - 1];
		index_a--;
	}
	while (index_b)
	{
		stacks->b_stack[index_b] = stacks->b_stack[index_b - 1];
		index_b--;
	}
	stacks->a_stack[0] = temp_a;
	stacks->b_stack[0] = temp_b;
	ft_printf("rr\n");
}
