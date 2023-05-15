#include "push_swap.h"

void	apply_rra(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->rra)
	{
		rra(stacks);
		i++;
	}
}

void	apply_rrb(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->rrb)
	{
		rrb(stacks);
		i++;
	}
}

void	apply_rrr(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->rrr)
	{
		rrr(stacks);
		i++;
	}
}
