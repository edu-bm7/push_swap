/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:30:54 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:30:55 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_mov_rot_handler(t_rotations *rot, int ra, int rb, int abs_r)
{
	if (ra > rb && is_min_mov(rb + ft_abs(ra - rb), rot))
	{
		rot->ra = abs_r;
		rot->rb = 0;
		rot->rr = rb;
		rot->mov_r = rb + ft_abs(ra - rb);
	}
	else if (ra < rb && is_min_mov(ra + ft_abs(ra - rb), rot))
	{
		rot->ra = 0;
		rot->rb = abs_r;
		rot->rr = ra;
		rot->mov_r = ra + ft_abs(rb - ra);
	}
	else if (ra == rb && is_min_mov(ra, rot))
	{
		rot->ra = abs_r;
		rot->rb = abs_r;
		rot->rr = ra;
		rot->mov_r = ra;
	}
	rot->movements[0] = rot->mov_r;
}

void	init_movements_rot(t_rotations *rot)
{
	int	ra;
	int	rb;
	int	abs_r;

	ra = rot->ra;
	rb = rot->rb;
	abs_r = ft_abs(ra - rb);
	init_mov_rot_handler(rot, ra, rb, abs_r);
}

void	init_mov_rev_rot_handler(t_rotations *rot, int rra, int rrb, int abs_rr)
{
	if (rra > rrb && is_min_mov(rrb + ft_abs(rra - rrb), rot))
	{
		rot->rra = abs_rr;
		rot->rrb = 0;
		rot->rrr = rrb;
		rot->mov_rr = rrb + ft_abs(rra - rrb);
	}
	else if (rra < rrb && is_min_mov(rra + ft_abs(rra - rrb), rot))
	{
		rot->rra = 0;
		rot->rrb = abs_rr;
		rot->rrr = rra;
		rot->mov_rr = rra + ft_abs(rrb - rra);
	}
	else if (rra == rrb && is_min_mov(rra, rot))
	{
		rot->rra = abs_rr;
		rot->rrb = abs_rr;
		rot->rrr = rra;
		rot->mov_rr = rra;
	}
	rot->movements[1] = rot->mov_rr;
}

void	init_movements_rev_rot(t_rotations *rot)
{
	int	rra;
	int	rrb;
	int	abs_rr;

	rra = rot->rra;
	rrb = rot->rrb;
	abs_rr = ft_abs(rra - rrb);
	init_mov_rev_rot_handler(rot, rra, rrb, abs_rr);
}

void	init_movements_array(t_rotations *rot)
{
	int	i;

	i = 0;
	rot->mov_r = 100000;
	rot->mov_rr = 100000;
	rot->mov_rra_rb = 100000;
	rot->mov_rrb_ra = 100000;
	while (i < MOVEMENTS)
	{
		rot->movements[i] = 100000;
		i++;
	}
}
