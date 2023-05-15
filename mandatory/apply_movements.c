#include "push_swap.h"


void	apply_movements(t_stacks *stacks)
{
	apply_ra(stacks);
	apply_rb(stacks);
	apply_rr(stacks);
	apply_rra(stacks);
	apply_rrb(stacks);
	apply_rrr(stacks);
}


