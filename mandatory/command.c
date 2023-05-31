#include "push_swap.h"

t_cmd	*allocate_cmd(const char *name)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (!cmd)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	cmd->name = name;
	cmd->next = NULL;
	return (cmd);
}

void	add_command(t_cmd_list *list, t_cmd *cmd)
{
	t_cmd	*tmp;

	if (!list->head)
		list->head = cmd;
	else
	{
		tmp = list->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cmd;
	}
	list->size++;
}
