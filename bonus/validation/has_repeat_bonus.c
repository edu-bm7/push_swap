#include "push_swap_bonus.h"

static void		init_hash_table(t_list *hash_table[],
					t_validation *validation);
static t_bool	search_hash_table(t_list *hash_table[], void *number);
static void		insert_into_htable(t_list *hash_table[], void *number);
static t_bool	check_split_param(char *str, t_list *hash_table[]);

t_bool	has_repeat(int argc, char *argv[], t_validation *validation)
{
	int		i;
	int		number;

	i = 1;
	init_hash_table(validation->ht, validation);
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			validation->has_quotes = true_;
			if (check_split_param(argv[i], validation->ht))
				return (true_);
		}
		else
		{
			number = ft_atoi(argv[i]);
			if (search_hash_table(validation->ht, (void *)(intptr_t)number))
				return (true_);
			else
				insert_into_htable(validation->ht, (void *)(intptr_t)number);
		}
		i++;
	}
	return (false_);
}

void	init_hash_table(t_list *hash_table[], t_validation *validation)
{
	int	i;

	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		hash_table[i] = NULL;
		i++;
	}
	validation->has_ht = true_;
}

t_bool	search_hash_table(t_list *hash_table[], void *number)
{
	int		hash;
	t_list	*current_node;

	hash = ft_abs((int)(intptr_t)number % HASH_TABLE_SIZE);
	current_node = hash_table[hash];
	while (current_node != NULL)
	{
		if (current_node->content == number)
			return (true_);
		current_node = current_node->next;
	}
	return (false_);
}

void	insert_into_htable(t_list *hash_table[], void *number)
{
	int		hash;
	t_list	*new_node;
	t_list	*current_node;

	hash = ft_abs((int)(intptr_t)number % HASH_TABLE_SIZE);
	new_node = ft_lstnew(number);
	if (!hash_table[hash])
		hash_table[hash] = new_node;
	else
	{
		current_node = hash_table[hash];
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
}

t_bool	check_split_param(char *str, t_list *hash_table[])
{
	int		number;
	size_t	words;
	char	**split;
	size_t	i;

	words = count_words(str, ' ');
	split = ft_split(str, ' ');
	i = 0;
	while (i < words)
	{
		number = ft_atoi(split[i]);
		if (search_hash_table(hash_table, (void *)(intptr_t) number))
		{
			free_str_array(split);
			return (true_);
		}
		else
			insert_into_htable(hash_table, (void *)(intptr_t) number);
		i++;
	}
	free_str_array(split);
	return (false_);
}
