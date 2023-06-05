/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:34:07 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:34:08 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b) || is_full(stack_a))
		return ;
	push(stack_a, pop(stack_b));
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a) || is_full(stack_b))
		return ;
	push(stack_b, pop(stack_a));
}
