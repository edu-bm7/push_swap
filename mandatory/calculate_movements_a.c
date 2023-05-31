#include "push_swap.h"

void	assign_stacks_values(t_stacks *stacks, t_rotations *rot
		, size_t movements)
{
	stacks->movements = movements;
	stacks->has_mov = true_;
	init_rot_vars(stacks);
	if (is_min_mov(rot->mov_r, rot))
	{
		stacks->ra = rot->ra;
		stacks->rb = rot->rb;
		stacks->rr = rot->rr;
	}
	else if (is_min_mov(rot->mov_rr, rot))
	{
		stacks->rra = rot->rra;
		stacks->rrb = rot->rrb;
		stacks->rrr = rot->rrr;
	}
	else if (is_min_mov(rot->mov_rra_rb, rot))
	{
		stacks->rra = rot->r_rra;
		stacks->rb = rot->r_rb;
	}
	else
	{
		stacks->rrb = rot->r_rrb;
		stacks->ra = rot->r_ra;
	}
}

t_bool	is_min_mov(int value, t_rotations *rot)
{
	int	i;

	i = 0;
	while (i < MOVEMENTS)
	{
		if (value > rot->movements[i])
			return (false_);
		i++;
	}
	return (true_);
}
