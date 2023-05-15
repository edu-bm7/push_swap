#include "push_swap.h"

void	calculate_rotations_a_to_b(t_stacks *stacks, int idx_a);

void	calculate_movements_a_to_b(t_stacks *stacks)
{
	int	a_top;

	a_top = stacks->a_top;
	while (a_top >= 0)
	{
		calculate_rotations_a_to_b(stacks, a_top);
		if (stacks->movements <= 1)
			return ;
		a_top--;
	}
}

void	calculate_rotations_a_to_b(t_stacks *stacks, int idx_a)
{
	t_rotations	rot;
	size_t		movements;
	int			index;

	index = get_b_placement(stacks->a_stack[idx_a], stacks);
	rot.ra = stacks->a_top - idx_a;
	rot.rb = stacks->b_top - index;
	rot.rra = idx_a + 1;
	rot.rrb = index + 1;
	init_movements_array(&rot);
	if (idx_a < (stacks->a_top + 1) / 2 && index > (stacks->b_top + 1) / 2)
		init_movements_rra_rb(&rot);
	else if (idx_a > (stacks->a_top + 1) / 2 && index < (stacks->b_top + 1) / 2)
		init_movements_rrb_ra(&rot);
	init_movements_rot(&rot);
	init_movements_rev_rot(&rot);
	if (is_min_mov(rot.mov_r, &rot))
		movements = rot.mov_r;
	else if (is_min_mov(rot.mov_rr, &rot))
		movements = rot.mov_rr;
	else if (is_min_mov(rot.mov_rra_rb, &rot))
		movements = rot.mov_rra_rb;
	else
		movements = rot.mov_rrb_ra;
	if (movements < stacks->movements)
		assign_stacks_values(stacks, &rot, movements);
}

void	assign_stacks_values(t_stacks *stacks, t_rotations *rot
		, size_t movements)
{
	stacks->movements = movements;
	if (is_min_mov(rot->mov_r, rot))
	{
		init_rot_vars(stacks);
		stacks->ra = rot->ra;
		stacks->rb = rot->rb;
		stacks->rr = rot->rr;
	}
	else if (is_min_mov(rot->mov_rr, rot))
	{
		init_rot_vars(stacks);
		stacks->rra = rot->rra;
		stacks->rrb = rot->rrb;
		stacks->rrr = rot->rrr;
	}
	else if (is_min_mov(rot->mov_rra_rb, rot))
	{
		init_rot_vars(stacks);
		stacks->rra = rot->r_rra;
		stacks->rb = rot->r_rb;
	}
	else
	{
		init_rot_vars(stacks);
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
