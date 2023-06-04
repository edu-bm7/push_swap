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
void		init_rot_vars(t_stacks *stacks);
void		calculate_movements_b_to_a(t_stacks *stacks);
t_cmd		*allocate_cmd(const char *name);
void		add_command(t_cmd_list *list, t_cmd *cmd);
int			get_a_placement(int value, t_stack *stack_a);
void		init_movements_rot(t_rotations *rot);
void		init_movements_rev_rot(t_rotations *rot);
void		init_movements_rra_rb(t_rotations *rot);
void		init_movements_rrb_ra(t_rotations *rot);
void		init_movements_array(t_rotations *rot);
t_bool		is_min_mov(int value, t_rotations *rot);
void		assign_stacks_values(t_stacks *stacks,
				t_rotations *rot, size_t movements);
size_t		find_index(t_stack *stack, int value);
void		apply_movements(t_stacks *stacks, t_cmd_list *list);
void		apply_ra(t_stacks *stacks, t_cmd_list *list);
void		apply_rb(t_stacks *stacks, t_cmd_list *list);
void		apply_rr(t_stacks *stacks, t_cmd_list *list);
void		apply_rra(t_stacks *stacks, t_cmd_list *list);
void		apply_rrb(t_stacks *stacks, t_cmd_list *list);
void		apply_rrr(t_stacks *stacks, t_cmd_list *list);
t_bool		is_empty(t_stack *stack);
t_bool		is_full(t_stack *stack);
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);
t_cmd_list	*sort_stacks(t_stacks *stacks);
void		sa(t_stack *stack_a, t_cmd_list *list);
void		pa(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list);
void		pb(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list);
void		ra(t_stack *stack, t_cmd_list *list);
void		rb(t_stack *stack, t_cmd_list *list);
void		rr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list);
void		rra(t_stack *stack, t_cmd_list *list);
void		rrb(t_stack *stack, t_cmd_list *list);
void		rrr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list);
void		push(t_stack *stack, t_node *new_node);
t_node		*pop(t_stack *stack);
t_node		*new_node(int number);
void		index_stack(t_stack *stack);
void		markup_index(t_stack *stack);
void		markup_gt(t_stack *stack);
size_t		index_keep_count(t_stack *stack, t_node *markup_head);
size_t		gt_keep_count(t_stack *stack, t_node *markup_head);
void		free_stacks(t_stacks *stacks);
void		free_cmd_list(t_cmd_list *list);
void		print_commands(t_cmd_list *list);
void		push_all_from_b_to_a(t_stacks *stacks, t_cmd_list *list);
void		init_stacks_vars(t_stacks *stacks, t_validation *validation,
				int argc, char *argv[]);

#endif