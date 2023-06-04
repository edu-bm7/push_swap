#include "push_swap_bonus.h"

void	apply_movements(t_stacks *stacks, char *str);
void	exit_error(t_stacks *stacks, char *str);

t_bool	stack_a_is_sorted(t_stacks *stacks)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		apply_movements(stacks, str);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	if (!is_empty(stacks->stack_b) || !is_full(stacks->stack_a)
		|| !is_sorted(stacks->stack_a))
		return (false_);
	return (true_);
}

void	apply_movements(t_stacks *stacks, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ra(stacks->stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stacks->stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stacks->stack_a, stacks->stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stacks->stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stacks->stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stacks->stack_a, stacks->stack_b);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(stacks->stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stacks->stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stacks->stack_a, stacks->stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stacks->stack_a, stacks->stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stacks->stack_a, stacks->stack_b);
	else
		exit_error(stacks, str);
}

void	exit_error(t_stacks *stacks, char *str)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	free(str);
	free_stacks(stacks);
	exit(1);
}
