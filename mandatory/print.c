#include "push_swap.h"

void	print_commands(t_cmd_list *list)
{
	t_cmd	*current;

	current = list->head;
	while (current)
	{
		ft_printf("%s\n", current->name);
		current = current->next;
	}
}
