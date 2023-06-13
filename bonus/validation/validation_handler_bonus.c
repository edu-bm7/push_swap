/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:53:46 by ebezerra          #+#    #+#             */
/*   Updated: 2023/06/13 19:53:47 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_bool	validate_handler(t_validation *validation, t_bool has_digit,
			char c, char *str)
{
	if (!has_digit || (c && !ft_isdigit(c))
		|| is_bigger_than_int(str))
		return (false_);
	if (ft_strchr(str, ' '))
	{
		validation->has_quotes = true_;
		if (!check_limits_str(str))
			return (false_);
	}
	return (true_);
}
