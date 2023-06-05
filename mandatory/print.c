/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:33 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:31:34 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
