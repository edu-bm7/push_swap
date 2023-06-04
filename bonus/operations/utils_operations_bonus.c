#include "push_swap_bonus.h"

t_bool	is_empty(t_stack *stack)
{
	if (!stack || !stack->head)
		return (true_);
	return (false_);
}

t_bool	is_full(t_stack *stack)
{
	if (!is_empty(stack) && stack->size == stack->full_size)
		return (true_);
	return (false_);
}

t_bool	is_sorted(t_stack *stack)
{
	size_t	i;
	t_node	*current;

	i = 0;
	current = stack->head;
	while (i < stack->size - 1)
	{
		if (current->number > current->next->number)
			return (false_);
		current = current->next;
		i++;
	}
	return (true_);
}
