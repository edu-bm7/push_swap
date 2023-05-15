#include "push_swap.h"

size_t find_b_max_index(t_stacks *stacks);

void	init_stack_b_vars(t_stacks *stacks)
{
	stacks->max_b = find_max(stacks->b_stack, stacks->b_top);
	stacks->min_b = find_min(stacks->b_stack, stacks->b_top);
	stacks->b_max_index = find_index(stacks->b_stack, stacks->max_b, stacks->b_top);
}

size_t find_b_max_index(t_stacks *stacks)
{
	int		top;
	size_t	index;

	top = stacks->b_top;
	index = (size_t)top;
	while(top != -1)
	{
		if (stacks->max_b == stacks->b_stack[top])
		{
			index = (size_t)top;
			return (index);
		}
		top--;
	}
	return (index);
}

int		get_b_placement(int value, t_stacks *stacks)
{
	int		b_top;

	b_top = stacks->b_top;
	if (value > stacks->b_stack[b_top] && value < stacks->b_stack[0])
		return (b_top);
	if (value > stacks->max_b || value < stacks->min_b)
		return (int)stacks->b_max_index;
	else
	{
		while(b_top > 0)
		{
			if ((value < stacks->b_stack[b_top]
				 && value > stacks->b_stack[b_top - 1]))
			{
				b_top--;
				return (b_top);
			}
			b_top--;
		}

	}
	return (0);
}

int		get_a_placement(int value, t_stacks *stacks)
{
	int		a_top;
	int		min;
	int		max;
	size_t	min_index;

	a_top = stacks->a_top;
	min = find_min(stacks->a_stack, a_top);
	max = find_max(stacks->a_stack, a_top);
	min_index = find_index(stacks->a_stack, min, a_top);
	if (value < stacks->a_stack[a_top] && value > stacks->a_stack[0])
		return (a_top);
	if (value < min || value > max)
		return (int)(min_index);
	else
	{
		while(a_top > 0)
		{
			if (value > stacks->a_stack[a_top] && value < stacks->a_stack[a_top - 1])
			{
				a_top--;
				return (a_top);
			}
			a_top--;
		}
	}
	return (0);
}

void	init_rot_vars(t_stacks *stacks)
{
	stacks->movements = 100000;
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;

}
