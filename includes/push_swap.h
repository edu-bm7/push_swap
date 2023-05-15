/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:26:16 by ebezerra          #+#    #+#             */
/*   Updated: 2023/02/09 22:52:27 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>

# define HASH_TABLE_SIZE 1000
# define MOVEMENTS 4
# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_stacks
{
	int		*a_stack;
	int		*b_stack;
	int		a_top;
	int		b_top;
	int		max_b;
	int		min_b;
	size_t	size;
	size_t 	movements;
	size_t 	b_max_index;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}		t_stacks;

typedef struct s_node
{
	int				number;
	size_t			index;
	t_bool			been_indexed;
	t_bool			keep_in_stack;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	size_t 	size;
	size_t 	keep_count;
	t_node	*markup_head;
}		t_stack;

typedef struct s_validation
{
	t_list	*ht[HASH_TABLE_SIZE];
	t_bool	has_quotes;
	t_bool	has_ht;
}		t_validation;

typedef struct s_rotations
{
	int ra;
	int rb;
	int rra;
	int rrb;
	int rrr;
	int rr;
	int	r_ra;
	int r_rb;
	int r_rra;
	int r_rrb;
	int mov_r;
	int mov_rr;
	int mov_rra_rb;
	int mov_rrb_ra;
	int movements[MOVEMENTS];
}		t_rotations;

t_bool	validate_numbers(char **argv, t_validation *validation);
void	free_hash_table(t_list *hash_table[]);
t_bool	is_bigger_than_int(const char *nptr);
t_bool	check_int_limits(long result, int digit);
t_bool	validate_params(int argc, char **argv, t_validation *validation);
t_bool	has_repeat(int argc, char *argv[], t_validation *validation);
void	init_stack_a(t_stack *stack_a, int argc, char *argv[]);
void	init_stack_b_vars(t_stacks *stacks);
void	init_rot_vars(t_stacks *stacks);
void	calculate_movements_a_to_b(t_stacks *stacks);
void	calculate_movements_b_to_a(t_stacks *stacks);
int		get_a_placement(int value, t_stacks *stacks);
int		get_b_placement(int value,t_stacks *stacks);
void	init_movements_rot(t_rotations *rot);
void	init_movements_rev_rot(t_rotations *rot);
void	init_movements_rra_rb(t_rotations *rot);
void	init_movements_rrb_ra(t_rotations *rot);
void	init_movements_array(t_rotations *rot);
t_bool	is_min_mov(int value, t_rotations *rot);
void	assign_stacks_values(t_stacks *stacks,
							 t_rotations *rot, size_t movements);
size_t	find_index(const int *arr, int value, int top);
void	apply_movements(t_stacks *stacks);
void	apply_ra(t_stacks *stacks);
void	apply_rb(t_stacks *stacks);
void	apply_rr(t_stacks *stacks);
void	apply_rra(t_stacks *stacks);
void	apply_rrb(t_stacks *stacks);
void	apply_rrr(t_stacks *stacks);
t_bool	is_empty(int top);
t_bool	is_full(int top, size_t size);
t_bool	is_sorted(const int *arr, int top);
int		find_min(const int *arr, int top);
int		find_max(const int *arr, int top);
void	sort_stacks(t_stacks *stacks);
void	print_stack_a(t_stacks *stacks);
void	print_stack_b(t_stacks *stacks);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

#endif