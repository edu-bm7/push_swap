#include "push_swap.h"
void	sort_3_or_less(t_stacks *stacks);
void	sort_more_than_3(t_stacks *stacks);
void	sort_till_3(t_stacks *stacks);
void	push_all_from_b_to_a(t_stacks *stacks);

void	sort_stacks(t_stacks *stacks)
{
	if (stacks->a_top < 3)
		sort_3_or_less(stacks);
	else
		sort_more_than_3(stacks);
}

void	sort_3_or_less(t_stacks *stacks)
{
	int top;

	top = stacks->a_top;
	if (find_min(stacks->a_stack, top) == stacks->a_stack[top])
	{
		if (!is_sorted(stacks->a_stack, top))
		{
			rra(stacks);
			sa(stacks);
		}
	}
	else if (find_max(stacks->a_stack, top) == stacks->a_stack[top])
	{
		ra(stacks);
		if (!is_sorted(stacks->a_stack, top))
			sa(stacks);
	}
	else
	{
		if (stacks->a_stack[top] > stacks->a_stack[top - 1])
			sa(stacks);
		else
			rra(stacks);
	}
}

void	sort_more_than_3(t_stacks *stacks)
{
	int	index;

	pb(stacks);
	pb(stacks);
	sort_till_3(stacks);
	sort_3_or_less(stacks);
	push_all_from_b_to_a(stacks);
	index = (int)find_index(stacks->a_stack, find_min(stacks->a_stack, stacks->a_top), stacks->a_top);
	if (index > stacks->a_top / 2)
	{
		stacks->ra = stacks->a_top - index;
		apply_ra(stacks);
	}
	else
	{
		stacks->rra = index + 1;
		apply_rra(stacks);
	}
}

void	sort_till_3(t_stacks *stacks)
{
	while(stacks->a_top > 2)
	{
		init_stack_b_vars(stacks);
		init_rot_vars(stacks);
		calculate_movements_a_to_b(stacks);
		apply_movements(stacks);
		pb(stacks);
	}
}
/*
 * while(a_top > 0 && (value > stacks->a_stack[a_top] && value < stacks->a_stack[a_top - 1]))
			a_top--;
 */

void	push_all_from_b_to_a(t_stacks *stacks)
{
	int index;
	int size;

	while(stacks->b_top >= 0)
	{
		index = get_a_placement(stacks->b_stack[stacks->b_top], stacks);
		size = stacks->a_top + 1;
		if (index > size / 2)
		{
			stacks->ra = stacks->a_top - index;
			apply_ra(stacks);
		}
		else if (index == size / 2)
		{
			if (size % 2 == 0)
			{
				stacks->ra = index - 1;
				apply_ra(stacks);
			}
			else
			{
				stacks->ra = index;
				apply_ra(stacks);
			}

		}
		else
		{
			stacks->rra = index + 1;
			apply_rra(stacks);
		}
//		init_rot_vars(stacks);
//		calculate_movements_b_to_a(stacks);
//		apply_movements(stacks);
		pa(stacks);
	}
}