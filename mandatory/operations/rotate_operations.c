/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:30:26 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:27 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, t_cmd_list *list)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->next;
	if (list)
		add_command(list, allocate_cmd("ra"));
}

void	rb(t_stack *stack, t_cmd_list *list)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->next;
	if (list)
		add_command(list, allocate_cmd("rb"));
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	ra(stack_a, NULL);
	rb(stack_b, NULL);
	if (list)
		add_command(list, allocate_cmd("rr"));
}
