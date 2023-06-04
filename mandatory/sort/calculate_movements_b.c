#include "push_swap.h"

static void	calculate_rotations_b_to_a(t_stacks *stacks, int nbr, int idx_b);
static void	assign_rot_vars(t_rotations *rot, t_stacks *stacks,
				int index, int idx_b);

void	push_all_from_b_to_a(t_stacks *stacks, t_cmd_list *list)
{
	int	b_top;

	if (stacks->stack_b->size > 0)
		b_top = (int)stacks->stack_b->size - 1;
	else
		b_top = -1;
	while (b_top >= 0)
	{
		stacks->has_mov = false_;
		init_rot_vars(stacks);
		calculate_movements_b_to_a(stacks);
		apply_movements(stacks, list);
		pa(stacks->stack_a, stacks->stack_b, list);
		b_top--;
	}
}

void	calculate_movements_b_to_a(t_stacks *stacks)
{
	int		b_top;
	t_node	*current;

	if (stacks->stack_b->size > 0)
		b_top = (int)stacks->stack_b->size - 1;
	else
		b_top = -1;
	current = stacks->stack_b->head;
	while (b_top >= 0)
	{
		calculate_rotations_b_to_a(stacks, current->number, b_top);
		if (stacks->movements <= 1)
			return ;
		current = current->next;
		b_top--;
	}
}

static void	calculate_rotations_b_to_a(t_stacks *stacks, int nbr, int idx_b)
{
	t_rotations	rot;
	size_t		movements;
	int			index;

	index = get_a_placement(nbr, stacks->stack_a);
	assign_rot_vars(&rot, stacks, index, idx_b);
	init_movements_array(&rot);
	if (idx_b > (int)stacks->stack_b->size / 2
		&& index < (int)stacks->stack_a->size / 2)
		init_movements_rra_rb(&rot);
	else if (idx_b < (int)stacks->stack_b->size / 2
		&& index > (int)stacks->stack_a->size / 2)
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

static void	assign_rot_vars(t_rotations *rot, t_stacks *stacks,
				int index, int idx_b)
{
	rot->ra = (int)(stacks->stack_a->size) - 1 - index;
	rot->rb = (int)(stacks->stack_b->size) - 1 - idx_b;
	rot->rra = index + 1;
	if ((int)(stacks->stack_b->size) - 1 > 0)
	{
		if (idx_b == (int)(stacks->stack_b->size) - 1)
			rot->rrb = 0;
		else
			rot->rrb = idx_b + 1;
	}
	else
		rot->rrb = idx_b;
}
