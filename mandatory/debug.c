#include "push_swap.h"

void	print_stack_a(t_stacks *stacks)
{
	int i;

	i = stacks->a_top;
	ft_printf("Stack A:\n");
	if (i < 0)
		return ;
	while(i >= 0)
	{
		ft_printf("%i\n", stacks->a_stack[i]);
		i--;
	}
}

void	print_stack_b(t_stacks *stacks)
{
	int i;

	i = stacks->b_top;
	ft_printf("Stack B:\n");
	if (i < 0)
		return ;
	while(i >= 0)
	{
		ft_printf("%i\n", stacks->b_stack[i]);
		i--;
	}
}
