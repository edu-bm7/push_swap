#include "push_swap.h"

void	apply_ra(t_stacks *stacks, t_cmd_list *list)
{
	size_t	i;

	i = 0;
	while (i < stacks->ra)
	{
		ra(stacks->stack_a, list);
		i++;
	}
}

void	apply_rb(t_stacks *stacks, t_cmd_list *list)
{
	size_t	i;

	i = 0;
	while (i < stacks->rb)
	{
		rb(stacks->stack_b, list);
		i++;
	}
}

void	apply_rr(t_stacks *stacks, t_cmd_list *list)
{
	size_t	i;

	i = 0;
	while (i < stacks->rr)
	{
		rr(stacks->stack_a, stacks->stack_b, list);
		i++;
	}
}
