/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash_table_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:34:22 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:34:23 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
