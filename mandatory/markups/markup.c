#include "push_swap.h"

void	markup_index(t_stack *stack)
{
	size_t	i;
	size_t	current_keep_count;
	t_node	*current;

	if (is_empty(stack))
		return ;
	i = 0;
	current = stack->head;
	stack->markup_index = true_;
	while (i < stack->size)
	{
		current_keep_count = index_keep_count(stack, current);
		if (current_keep_count > stack->keep_count)
		{
			stack->markup_head = current;
			stack->keep_count = current_keep_count;
		}
		else if (current_keep_count == stack->keep_count
			&& (!stack->markup_head
				|| current->number < stack->markup_head->number))
			stack->markup_head = current;
		i++;
		current = current->next;
	}
	index_keep_count(stack, stack->markup_head);
}

size_t	index_keep_count(t_stack *stack, t_node *markup_head)
{
	size_t	index;
	size_t	keep_count;
	t_node	*current;

	if (is_empty(stack) || !markup_head)
		return (0);
	keep_count = 0;
	index = markup_head->index;
	markup_head->keep_in_stack = true_;
	current = markup_head->next;
	while (current != markup_head)
	{
		if (current->index == index + 1)
		{
			index++;
			keep_count++;
			current->keep_in_stack = true_;
		}
		else
			current->keep_in_stack = false_;
		current = current->next;
	}
	return (keep_count);
}

void	markup_gt(t_stack *stack)
{
	size_t	i;
	size_t	current_keep_count;
	t_node	*current;

	if (is_empty(stack))
		return ;
	i = 0;
	current = stack->head;
	stack->markup_index = false_;
	while (i < stack->size)
	{
		current_keep_count = gt_keep_count(stack, current);
		if (current_keep_count > stack->keep_count)
		{
			stack->markup_head = current;
			stack->keep_count = current_keep_count;
		}
		else if (current_keep_count == stack->keep_count
			&& (!stack->markup_head
				|| current->number < stack->markup_head->number))
			stack->markup_head = current;
		i++;
		current = current->next;
	}
	gt_keep_count(stack, stack->markup_head);
}

size_t	gt_keep_count(t_stack *stack, t_node *markup_head)
{
	size_t	index;
	size_t	keep_count;
	t_node	*current;

	if (is_empty(stack) || !markup_head)
		return (0);
	keep_count = 1;
	index = markup_head->index;
	markup_head->keep_in_stack = true_;
	current = markup_head->next;
	while (current != markup_head)
	{
		if (current->index > index)
		{
			index = current->index;
			keep_count++;
			current->keep_in_stack = true_;
		}
		else
			current->keep_in_stack = false_;
		current = current->next;
	}
	return (keep_count);
}
