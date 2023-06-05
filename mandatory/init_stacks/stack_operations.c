/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:30:12 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:13 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int number)
{
	t_node	*tmp;

	tmp = malloc(sizeof (*tmp));
	if (!tmp)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	tmp->number = number;
	tmp->index = 0;
	tmp->been_indexed = false_;
	tmp->keep_in_stack = false_;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

void	push(t_stack *stack, t_node *new_node)
{
	t_node	*tail;

	if (!stack->head)
	{
		stack->head = new_node;
		new_node->previous = stack->head;
		new_node->next = stack->head;
	}
	else
	{
		tail = stack->head->previous;
		new_node->next = stack->head;
		stack->head->previous = new_node;
		new_node->previous = tail;
		tail->next = new_node;
		stack->head = new_node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	if (is_empty(stack))
		return (NULL);
	if (stack->head == stack->head->next)
	{
		stack->head = NULL;
		tmp->next = NULL;
		tmp->previous = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->previous = tmp->previous;
		tmp->previous->next = stack->head;
		tmp->next = NULL;
		tmp->previous = NULL;
	}
	stack->size--;
	return (tmp);
}
