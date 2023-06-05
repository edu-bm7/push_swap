/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_movements_r_rr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:30:51 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:52 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_movements_rra_rb(t_rotations *rot)
{
	rot->r_rra = rot->rra;
	rot->r_rb = rot->rb;
	rot->mov_rra_rb = rot->r_rra + rot->r_rb;
	rot->movements[2] = rot->mov_rra_rb;
}

void	init_movements_rrb_ra(t_rotations *rot)
{
	rot->r_rrb = rot->rrb;
	rot->r_ra = rot->ra;
	rot->mov_rrb_ra = rot->r_rrb + rot->r_ra;
	rot->movements[3] = rot->mov_rrb_ra;
}
