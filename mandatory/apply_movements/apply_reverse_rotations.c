/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_reverse_rotations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:29:59 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:00 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rra(t_stacks *stacks, t_cmd_list *list)
{
	size_t	i;

	i = 0;
	while (i < stacks->rra)
	{
		rra(stacks->stack_a, list);
		i++;
	}
}

void	apply_rrb(t_stacks *stacks, t_cmd_list *list)
{
	size_t	i;

	i = 0;
	while (i < stacks->rrb)
	{
		rrb(stacks->stack_b, list);
		i++;
	}
}

void	apply_rrr(t_stacks *stacks, t_cmd_list *list)
{
	size_t	i;

	i = 0;
	while (i < stacks->rrr)
	{
		rrr(stacks->stack_a, stacks->stack_b, list);
		i++;
	}
}
