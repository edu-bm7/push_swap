#include "push_swap.h"

void	deal_with_str(t_stack *stack_a,char *str);
void	push(t_stack *stack, int number);

void	init_stack_a(t_stack *stack_a, int argc, char *argv[])
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		if (ft_strchr(argv[index], ' '))
			deal_with_str(stack_a, argv[index]);
		else
			push(stack_a, ft_atoi(argv[index]));
		index--;
	}
}

t_node	*stack_new(int number)
{
	t_node	*tmp;

	tmp = malloc(sizeof (*tmp));
	if (!tmp)
		return (NULL);
	tmp->number = number;
	tmp->index = 0;
	tmp->been_indexed = false_;
	tmp->keep_in_stack = false_;
	tmp->next = NULL;
	return (tmp);
}

void	push(t_stack *stack, int number)
{
	t_node	*new_node;

	new_node = stack_new(number);
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	deal_with_str(t_stack *stack_a, char *str)
{
	size_t	i;
	char	**split;

	i = count_words(str, ' ') - 1;
	split = ft_split(str, ' ');
	while (i > 0)
	{
		push(stack_a, ft_atoi(split[i]));
		i--;
		if (i == 0)
			push(stack_a, ft_atoi(split[i]));
	}
}
