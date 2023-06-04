#include "push_swap.h"

t_cmd_list	*init_cmd_list(void)
{
	t_cmd_list	*list;

	list = ft_calloc(1, sizeof(*list));
	if (!list)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	list->head = NULL;
	list->size = 0;
	return (list);
}

t_bool	has_pb(t_stack *stack_a)
{
	size_t	i;
	t_node	*current;

	if (is_empty(stack_a))
		return (false_);
	i = 0;
	current = stack_a->head;
	while (i < stack_a->size)
	{
		if (!current->keep_in_stack)
			return (true_);
		current = current->next;
		i++;
	}
	return (false_);
}

t_bool	should_sa(t_stack *stack_a)
{
	size_t	current_keep_count;

	if (!is_empty(stack_a) && stack_a->size > 1)
	{
		sa(stack_a, NULL);
		if (stack_a->markup_index)
			current_keep_count = index_keep_count(
					stack_a, stack_a->markup_head
					);
		else
			current_keep_count = gt_keep_count(stack_a, stack_a->markup_head);
		sa(stack_a, NULL);
		if (stack_a->markup_index)
			stack_a->keep_count = index_keep_count(
					stack_a, stack_a->markup_head
					);
		else
			stack_a->keep_count = gt_keep_count(stack_a, stack_a->markup_head);
		if (current_keep_count > stack_a->keep_count)
			return (true_);
	}
	return (false_);
}

void	sort_a(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	while (has_pb(stack_a))
	{
		if (should_sa(stack_a))
		{
			sa(stack_a, list);
			if (stack_a->markup_index)
				stack_a->keep_count = index_keep_count(
						stack_a, stack_a->markup_head
						);
			else
				stack_a->keep_count = gt_keep_count(
						stack_a, stack_a->markup_head
						);
		}
		else if (!stack_a->head->keep_in_stack)
			pb(stack_a, stack_b, list);
		else
			ra(stack_a, list);
	}
}

t_cmd_list	*sort_stacks(t_stacks *stacks)
{
	t_cmd_list	*list;
	int			index;

	list = init_cmd_list();
	sort_a(stacks->stack_a, stacks->stack_b, list);
	push_all_from_b_to_a(stacks, list);
	index = (int)find_index(stacks->stack_a, find_min(stacks->stack_a));
	if (index >= (int)(stacks->stack_a->size - 1) / 2)
	{
		stacks->ra = (int)(stacks->stack_a->size - 1) - index;
		apply_ra(stacks, list);
	}
	else
	{
		stacks->rra = index + 1;
		apply_rra(stacks, list);
	}
	return (list);
}
