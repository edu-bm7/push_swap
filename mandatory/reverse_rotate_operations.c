#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	int i;
	int temp;


	i = 0;
	temp = stacks->a_stack[0];
	if (stacks->a_top == 0)
		return ;
	while (i < stacks->a_top)
	{
		stacks->a_stack[i] = stacks->a_stack[i + 1];
		i++;
	}
	stacks->a_stack[stacks->a_top] = temp;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	int i;
	int temp;

	i = 0;
	temp = stacks->b_stack[0];
	if (stacks->b_top == 0)
		return ;
	while (i < stacks->b_top)
	{
		stacks->b_stack[i] = stacks->b_stack[i + 1];
		i++;
	}
	stacks->b_stack[stacks->b_top] = temp;
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	int index;
	int temp_b;
	int temp_a;

	index = 0;
	temp_a = stacks->a_stack[0];
	temp_b = stacks->b_stack[0];
	if (stacks->a_top == 0 || stacks->b_top == 0)
		return ;
	while (index < stacks->b_top)
	{
		stacks->b_stack[index] = stacks->b_stack[index + 1];
		index++;
	}
	index = 0;
	while (index < stacks->a_top)
	{
		stacks->a_stack[index] = stacks->a_stack[index + 1];
		index++;
	}
	stacks->a_stack[stacks->a_top] = temp_a;
	stacks->b_stack[stacks->b_top] = temp_b;
	ft_printf("rrr\n");
}
