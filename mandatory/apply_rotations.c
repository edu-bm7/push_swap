#include "push_swap.h"

void	apply_ra(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->ra)
	{
		ra(stacks);
		i++;
	}
}

void	apply_rb(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->rb)
	{
		rb(stacks);
		i++;
	}
}

void	apply_rr(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->rr)
	{
		rr(stacks);
		i++;
	}
}
