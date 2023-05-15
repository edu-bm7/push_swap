#include "push_swap.h"

void	calculate_rotations_b_to_a(t_stacks *stacks, int idx_b);

void	calculate_movements_b_to_a(t_stacks *stacks)
{
	int	b_top;

	b_top = stacks->b_top;
	while (b_top >= 0)
	{
		calculate_rotations_b_to_a(stacks, b_top);
		if (stacks->movements <= 1)
			return ;
		b_top--;
	}
}

void	calculate_rotations_b_to_a(t_stacks *stacks, int idx_b)
{
	t_rotations	rot;
	size_t		movements;
	int			index;

	index = get_a_placement(stacks->b_stack[idx_b], stacks);
	rot.ra = stacks->a_top - index;
	rot.rb = stacks->b_top - idx_b;
	rot.rra = index + 1;
	if (stacks->b_top > 0)
		rot.rrb = idx_b + 1;
	else
		rot.rrb = idx_b;
	init_movements_array(&rot);
	if (idx_b > (stacks->b_top + 1) / 2 && index < (stacks->a_top + 1) / 2)
		init_movements_rra_rb(&rot);
	else if (idx_b < (stacks->b_top + 1) / 2 && index > (stacks->a_top + 1) / 2)
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
