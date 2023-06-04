#include "push_swap.h"

static void		deal_with_str(t_stack *stack_a, char *str);
static void		allocate_stacks(t_stacks *stacks);
static size_t	get_stack_size(int argc, char *argv[]);
static void		init_stack_a(t_stack *stack_a, int argc, char *argv[]);

void	init_stacks_vars(t_stacks *stacks, t_validation *validation,
			int argc, char *argv[])
{
	allocate_stacks(stacks);
	if (validation->has_quotes)
	{
		stacks->stack_a->full_size = get_stack_size(argc, argv);
		stacks->stack_b->full_size = stacks->stack_a->full_size;
	}
	else
	{
		stacks->stack_a->full_size = argc - 1;
		stacks->stack_b->full_size = stacks->stack_a->full_size;
	}
	stacks->stack_a->size = 0;
	stacks->stack_a->head = NULL;
	stacks->stack_a->keep_count = 0;
	stacks->stack_a->markup_head = NULL;
	stacks->stack_b->size = 0;
	stacks->stack_b->head = NULL;
	stacks->stack_b->keep_count = 0;
	stacks->stack_b->markup_head = NULL;
	init_stack_a(stacks->stack_a, argc, argv);
}

static size_t	get_stack_size(int argc, char *argv[])
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

static void	allocate_stacks(t_stacks *stacks)
{
	stacks->stack_a = ft_calloc(1, sizeof(*stacks->stack_a));
	if (!stacks->stack_a)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	stacks->stack_b = ft_calloc(1, sizeof(*stacks->stack_b));
	if (!stacks->stack_b)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
}

static void	init_stack_a(t_stack *stack_a, int argc, char *argv[])
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		if (ft_strchr(argv[index], ' '))
			deal_with_str(stack_a, argv[index]);
		else
			push(stack_a, new_node(ft_atoi(argv[index])));
		index--;
	}
}

static void	deal_with_str(t_stack *stack_a, char *str)
{
	size_t	i;
	char	**split;

	i = count_words(str, ' ') - 1;
	split = ft_split(str, ' ');
	while (i > 0)
	{
		push(stack_a, new_node(ft_atoi(split[i])));
		i--;
		if (i == 0)
			push(stack_a, new_node(ft_atoi(split[i])));
	}
	free_str_array(split);
}
