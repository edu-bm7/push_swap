#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	min = stack->head->number;
	current = stack->head->next;
	while (current != stack->head)
	{
		if (current->number < min)
			min = current->number;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	max = stack->head->number;
	current = stack->head->next;
	while (current != stack->head)
	{
		if (current->number > max)
			max = current->number;
		current = current->next;
	}
	return (max);
}

t_bool	is_sorted(const int *arr, int top)
{
	while (top)
	{
		if (arr[top] > arr[top - 1])
			return (false_);
		top--;
	}
	return (true_);
}

size_t	find_index(t_stack *stack, int value)
{
	int		index;
	t_node	*current;

	if (stack->size > 0)
		index = (int)stack->size - 1;
	else
		return (0);
	current = stack->head;
	while (index != -1)
	{
		if (current->number == value)
			return (index);
		current = current->next;
		index--;
	}
	return (index);
}
