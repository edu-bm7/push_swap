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
	t_stack stack_a;
	t_stack stack_b;
	t_validation validation;

	validation.has_ht = false_;
	validation.has_quotes = false_;
	if (argc < 2)
		return (0);
	if (!validate_params(argc, argv, &validation))
	{
		if (validation.has_ht)
			free_hash_table(validation.ht);
		return (1);
	}
	free_hash_table(validation.ht);
	init_stacks_vars(&stack_a, &stack_b);
	init_stack_a(&stack_a, argc, argv);
//	sort_stacks(&stacks);
//	if (DEBUG)
//	{
//		print_stack_a(&stacks);
//		print_stack_b(&stacks);
//	}
//	free(stacks.a_stack);
//	free(stacks.b_stack);
	return (0);
}

void	init_stacks_vars(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->top = NULL;
	stack_a->keep_count = 0;
	stack_a->markup_head = NULL;
	stack_b->size = 0;
	stack_b->top = NULL;
	stack_b->keep_count = 0;
	stack_b->markup_head = NULL;
}

size_t get_stack_size(int argc, char *argv[])
{
	size_t	words;
	int 	i;

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
