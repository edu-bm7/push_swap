/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:23:56 by ebezerra          #+#    #+#             */
/*   Updated: 2023/02/09 22:33:31 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks_vars(t_stack *stack_a, t_stack *stack_b);
size_t		get_stack_size(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_stacks		stacks;
	t_validation	validation;
	t_cmd_list		*index_list;
	t_cmd_list		*gt_list;

	validation.has_ht = false_;
	validation.has_quotes = false_;
	if (argc < 2)
		return (0);
	if (!validate_params(argc, argv, &validation))
	{
		if (validation.has_ht)
			free_hash_table(validation.ht);
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (1);
	}
	free_hash_table(validation.ht);
	stacks.stack_a = ft_calloc(1, sizeof(*stacks.stack_a));
	stacks.stack_b = ft_calloc(1, sizeof(*stacks.stack_b));
	if (validation.has_quotes)
	{
		stacks.stack_a->full_size = get_stack_size(argc, argv);
		stacks.stack_b->full_size = stacks.stack_a->full_size;
	}
	else
	{
		stacks.stack_a->full_size = argc - 1;
		stacks.stack_b->full_size = stacks.stack_a->full_size;
	}
	init_stacks_vars(stacks.stack_a, stacks.stack_b);
	init_stack_a(stacks.stack_a, argc, argv);
	index_stack(stacks.stack_a);
	markup_index(stacks.stack_a);
	index_list = sort_stacks(&stacks);
	free_stacks(stacks.stack_a);
	free_stacks(stacks.stack_b);
	stacks.stack_a = ft_calloc(1, sizeof(*stacks.stack_a));
	stacks.stack_b = ft_calloc(1, sizeof(*stacks.stack_b));
	init_stacks_vars(stacks.stack_a, stacks.stack_b);
	init_stack_a(stacks.stack_a, argc, argv);
	index_stack(stacks.stack_a);
	markup_gt(stacks.stack_a);
	gt_list = sort_stacks(&stacks);
	if (index_list->size < gt_list->size)
		print_commands(index_list);
	else
		print_commands(gt_list);
	free_stacks(stacks.stack_a);
	free_stacks(stacks.stack_b);
	free_cmd_list(index_list);
	free_cmd_list(gt_list);
	return (0);
}

void	init_stacks_vars(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->head = NULL;
	stack_a->keep_count = 0;
	stack_a->markup_head = NULL;
	stack_b->size = 0;
	stack_b->head = NULL;
	stack_b->keep_count = 0;
	stack_b->markup_head = NULL;
}

size_t	get_stack_size(int argc, char *argv[])
{
	size_t	words;
	int		i;

	i = 1;
	words = argc - 2;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			words += count_words(argv[i], ' ');
		i++;
	}
	return (words);
}
