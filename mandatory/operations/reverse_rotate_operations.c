#include "push_swap.h"

void	rra(t_stack *stack, t_cmd_list *list)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->previous;
	if (list)
		add_command(list, allocate_cmd("rra"));
}

void	rrb(t_stack *stack, t_cmd_list *list)
{
	if (is_empty(stack))
		return ;
	stack->head = stack->head->previous;
	if (list)
		add_command(list, allocate_cmd("rrb"));
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	rra(stack_a, NULL);
	rrb(stack_b, NULL);
	if (list)
		add_command(list, allocate_cmd("rrr"));
}
