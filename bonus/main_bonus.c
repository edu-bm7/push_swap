/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:23:56 by ebezerra          #+#    #+#             */
/*   Updated: 2023/02/09 23:26:43 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stacks		stacks;
	t_validation	validation;

	if (argc >= 2)
	{
		validate_params(argc, argv, &validation);
		init_stacks_vars(&stacks, &validation, argc, argv);
		if (!stack_a_is_sorted(&stacks))
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
		free_stacks(&stacks);
	}
	return (0);
}
