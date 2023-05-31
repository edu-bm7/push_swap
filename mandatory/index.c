#include "push_swap.h"

static t_node	*get_min(t_stack *stack);

void	index_stack(t_stack *stack)
{
	size_t	index;
	t_node	*tmp;

	index = 0;
	tmp = get_min(stack);
	while (tmp)
	{
		tmp->index = index++;
		tmp->been_indexed = true_;
		tmp = get_min(stack);
	}
}

static t_node	*get_min(t_stack *stack)
{
	t_node	*min;
	size_t	i;
	t_node	*tmp;
	t_bool	has_min;

	if (!stack)
		return (NULL);
	i = 0;
	has_min = false_;
	tmp = stack->head;
	min = NULL;
	while (i < stack->size)
	{
		if (!tmp->been_indexed && (!has_min || tmp->number < min->number))
		{
			has_min = true_;
			min = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (min);
}
