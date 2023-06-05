/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_placements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:30:47 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:48 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_middle_placement(t_node *current, int a_top, int value)
{
	while (a_top > 0)
	{
		if (value > current->number && value < current->next->number)
		{
			a_top--;
			return (a_top);
		}
		current = current->next;
		a_top--;
	}
	return (0);
}

int	get_a_placement(int value, t_stack *stack_a)
{
	int		a_top;
	int		min;
	int		max;
	size_t	min_index;
	t_node	*current;

	if (stack_a->size > 0)
		a_top = (int)stack_a->size - 1;
	else
		a_top = -1;
	min = find_min(stack_a);
	max = find_max(stack_a);
	min_index = find_index(stack_a, min);
	current = stack_a->head;
	if (value < stack_a->head->number
		&& value > stack_a->head->previous->number)
		return (a_top);
	if (value < min || value > max)
		return ((int)(min_index));
	return (get_middle_placement(current, a_top, value));
}

void	init_rot_vars(t_stacks *stacks)
{
	if (!stacks->has_mov)
		stacks->movements = 100000;
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;
}
