/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_validation_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:34:27 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/05 18:34:28 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

#define MAX_INT 2147483647
#define MIN_INT_STR "-2147483648"

static t_bool	validate_numbers(char *argv[], t_validation *validation);
static t_bool	check_int_limits(long result, int digit);

void	validate_params(int argc, char *argv[], t_validation *validation)
{
	validation->has_ht = false_;
	validation->has_quotes = false_;
	if (!validate_numbers(argv, validation)
		|| has_repeat(argc, argv, validation))
	{
		if (validation->has_ht)
			free_hash_table(validation->ht);
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	free_hash_table(validation->ht);
}

static t_bool	validate_numbers(char *argv[], t_validation *validation)
{
	int		i;
	int		j;
	t_bool	has_digit;

	i = 1;
	while (argv[i])
	{
		j = 0;
		has_digit = false_;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (ft_isdigit(argv[i][j]) || argv[i][j] == ' ')
		{
			if (ft_isdigit(argv[i][j]))
				has_digit = true_;
			j++;
		}
		if (!validate_handler(validation, has_digit, argv[i][j], argv[i]))
			return (false_);
		i++;
	}
	return (true_);
}

t_bool	is_bigger_than_int(const char *nptr)
{
	long	result;
	int		digit;

	result = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (ft_strcmp(MIN_INT_STR, nptr) == 0)
		return (false_);
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (check_int_limits(result, digit))
			return (true_);
		result = result * 10 + *nptr++ - '0';
	}
	return (false_);
}

static t_bool	check_int_limits(long result, int digit)
{
	if (result > MAX_INT / 10
		|| (result == MAX_INT / 10 && digit > MAX_INT % 10))
		return (true_);
	return (false_);
}

t_bool	check_limits_str(char *str)
{
	size_t	words;
	char	**split;
	size_t	i;

	i = 0;
	words = count_words(str, ' ');
	split = ft_split(str, ' ');
	while (i < words)
	{
		if (is_bigger_than_int(split[i]))
		{
			free_str_array(split);
			return (false_);
		}
		i++;
	}
	free_str_array(split);
	return (true_);
}
