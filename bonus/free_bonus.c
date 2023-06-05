/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:34:30 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:34:31 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_stack(t_stack *stack);

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
