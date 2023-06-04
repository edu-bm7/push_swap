/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:52:57 by ebezerra          #+#    #+#             */
/*   Updated: 2023/02/09 22:59:47 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <unistd.h>

# define HASH_TABLE_SIZE 1000
# define MOVEMENTS 4
# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_node
{
	int				number;
	size_t			index;
	t_bool			been_indexed;
	t_bool			keep_in_stack;
	struct s_node	*previous;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node	*head;
	size_t	size;
	size_t	full_size;
	t_bool	markup_index;
	size_t	keep_count;
	t_node	*markup_head;
}		t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_bool	has_mov;
	size_t	movements;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}		t_stacks;

typedef struct s_validation
{
	t_list	*ht[HASH_TABLE_SIZE];
	t_bool	has_quotes;
	t_bool	has_ht;
}		t_validation;

typedef struct s_cmd
{
	const char		*name;
	struct s_cmd	*next;
}		t_cmd;

typedef struct s_cmd_list
{
	size_t	size;
	t_cmd	*head;
}		t_cmd_list;

typedef struct s_rotations
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rrr;
	int	rr;
	int	r_ra;
	int	r_rb;
	int	r_rra;
	int	r_rrb;
	int	mov_r;
	int	mov_rr;
	int	mov_rra_rb;
	int	mov_rrb_ra;
	int	movements[MOVEMENTS];
}		t_rotations;

void		free_hash_table(t_list *hash_table[]);
void		validate_params(int argc, char **argv, t_validation *validation);
t_bool		has_repeat(int argc, char *argv[], t_validation *validation);
void		init_stacks_vars(t_stacks *stacks, t_validation *validation,
				int argc, char *argv[]);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack *stack, t_node *new_node);
t_node		*pop(t_stack *stack);
t_node		*new_node(int number);
t_bool		is_empty(t_stack *stack);
t_bool		is_full(t_stack *stack);
t_bool		is_sorted(t_stack *stack);
t_bool		stack_a_is_sorted(t_stacks *stacks);
void		free_stacks(t_stacks *stacks);

#endif
