/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:26 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:31:27 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack);

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

void	free_stacks(t_stacks *stacks)
{
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
}

static void	free_stack(t_stack *stack)
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
