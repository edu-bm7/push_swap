/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:23:56 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:31:31 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks		stacks;
	t_validation	validation;
	t_cmd_list		*index_list;
	t_cmd_list		*gt_list;

	if (argc < 2)
		return (0);
	validate_params(argc, argv, &validation);
	init_stacks_vars(&stacks, &validation, argc, argv);
	index_stack(stacks.stack_a);
	markup_index(stacks.stack_a);
	index_list = sort_stacks(&stacks);
	free_stacks(&stacks);
	init_stacks_vars(&stacks, &validation, argc, argv);
	index_stack(stacks.stack_a);
	markup_gt(stacks.stack_a);
	gt_list = sort_stacks(&stacks);
	if (index_list->size < gt_list->size)
		print_commands(index_list);
	else
		print_commands(gt_list);
	free_stacks(&stacks);
	free_cmd_list(index_list);
	free_cmd_list(gt_list);
	return (0);
}
