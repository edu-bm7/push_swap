/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:30:21 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:22 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	if (is_empty(stack_b) || is_full(stack_a))
		return ;
	push(stack_a, pop(stack_b));
	if (list)
		add_command(list, allocate_cmd("pa"));
}

void	pb(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	if (is_empty(stack_a) || is_full(stack_b))
		return ;
	push(stack_b, pop(stack_a));
	if (list)
		add_command(list, allocate_cmd("pb"));
}
