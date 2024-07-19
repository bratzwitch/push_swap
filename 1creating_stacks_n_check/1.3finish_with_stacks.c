/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.3finish_with_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:14:48 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:07:30 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_splitted(char ***splitted)
{
	int	i;

	i = 0;
	while ((*splitted)[i])
	{
		free((*splitted)[i]);
		i++;
	}
	free(*splitted);
	return (0);
}

int	fill_stack(t_stack *a, int num_digit, char **argv)
{
	int		i;
	char	**splitted;
	int		j;
	long	lnum;

	i = 1;
	while (num_digit)
	{
		j = 0;
		splitted = ft_split(argv[i++], ' ');
		if (!splitted)
			return (-1);
		while (splitted[j])
		{
			if (ft_strlen(splitted[j]) > 12)
				return (free_splitted(&splitted));
			lnum = atol(splitted[j++]);
			if (lnum > 2147483647 || lnum < -2147483648)
				return (free_splitted(&splitted));
			a->stack[--num_digit] = (int)lnum;
		}
		free_splitted(&splitted);
	}
	a->first = a->stack[a->len - 1];
	return (1);
}

long	atol(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
