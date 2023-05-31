#include "push_swap.h"

void	free_node(t_list *head)
{
	if (head == NULL)
		return ;
	free_node(head->next);
	free(head);
}

void	free_hash_table(t_list *hash_table[])
{
	int	i;

	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		free_node(hash_table[i]);
		i++;
	}
}
