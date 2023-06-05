/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:29:56 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:29:57 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_movements(t_stacks *stacks, t_cmd_list *list)
{
	apply_ra(stacks, list);
	apply_rb(stacks, list);
	apply_rr(stacks, list);
	apply_rra(stacks, list);
	apply_rrb(stacks, list);
	apply_rrr(stacks, list);
}
