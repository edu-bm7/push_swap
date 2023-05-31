#include "push_swap.h"

void	free_cmd_list(t_cmd_list *list)
{
	t_cmd	*current;
	t_cmd	*tmp;

	current = list->head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(list);
	list = NULL;
}

void	free_stacks(t_stack *stack)
{
	size_t	i;
	t_node	*tmp;
	t_node	*current;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		i++;
	}
	free(stack);
	stack = NULL;
}
