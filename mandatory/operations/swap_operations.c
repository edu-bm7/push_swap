#include "push_swap.h"

static t_node	*swap(t_node *head);

void	sa(t_stack *stack_a, t_cmd_list *list)
{
	if (stack_a->size > 1)
		stack_a->head = swap(stack_a->head);
	if (list)
		add_command(list, allocate_cmd("sa"));
}

void	sb(t_stack *stack_b, t_cmd_list *list)
{
	if (stack_b->size > 1)
		stack_b->head = swap(stack_b->head);
	if (list)
		add_command(list, allocate_cmd("sb"));
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	sa(stack_a, NULL);
	sb(stack_b, NULL);
	if (list)
		add_command(list, allocate_cmd("ss"));
}

static t_node	*swap(t_node *head)
{
	t_node	*tmp_head;
	t_node	*tmp_next;

	tmp_head = head;
	tmp_next = head->next;
	tmp_head->next = tmp_next->next;
	tmp_next->next->previous = tmp_head;
	tmp_next->next = tmp_head;
	tmp_next->previous = tmp_head->previous;
	tmp_next->previous->next = tmp_next;
	tmp_head->previous = tmp_next;
	return (tmp_next);
}
