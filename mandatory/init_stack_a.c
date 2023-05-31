#include "push_swap.h"

void	deal_with_str(t_stack *stack_a, char *str);

void	init_stack_a(t_stack *stack_a, int argc, char *argv[])
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		if (ft_strchr(argv[index], ' '))
			deal_with_str(stack_a, argv[index]);
		else
			push(stack_a, new_node(ft_atoi(argv[index])));
		index--;
	}
}

void	deal_with_str(t_stack *stack_a, char *str)
{
	size_t	i;
	char	**split;

	i = count_words(str, ' ') - 1;
	split = ft_split(str, ' ');
	while (i > 0)
	{
		push(stack_a, new_node(ft_atoi(split[i])));
		i--;
		if (i == 0)
			push(stack_a, new_node(ft_atoi(split[i])));
	}
}
