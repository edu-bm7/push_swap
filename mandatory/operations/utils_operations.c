/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:30:36 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:37 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_empty(t_stack *stack)
{
	if (!stack || !stack->head)
		return (true_);
	return (false_);
}

t_bool	is_full(t_stack *stack)
{
	if (!is_empty(stack) && stack->size == stack->full_size)
		return (true_);
	return (false_);
}
