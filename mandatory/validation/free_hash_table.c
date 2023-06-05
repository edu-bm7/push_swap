/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:13 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:31:14 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
