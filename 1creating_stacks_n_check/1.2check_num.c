/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.2check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:08:24 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:10:05 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_of_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	total = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				if (argv[i][j + 1] == ' ' || !argv[i][j + 1])
					total += 1;
			j++;
		}
		i++;
	}
	return (total);
}

int	is_digit_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_digit_str(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
		{
			if (str[i] == '-')
			{
				if (!ft_isdigit(str[i + 1]))
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}
