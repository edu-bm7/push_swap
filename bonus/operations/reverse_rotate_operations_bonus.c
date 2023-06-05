/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:34:09 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:34:10 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->previous;
}

void	rrb(t_stack *stack)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->previous;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
