/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1actual_finding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:21:09 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:07:36 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_duplicates(t_stack st)
{
	int	i;

	i = 0;
	while (i < st.len)
	{
		if (get_pos(st, st.stack[i]) != i)
			return (1);
		i++;
	}
	return (0);
}

int	get_pos(t_stack st, int num)
{
	int	i;

	i = 0;
	while (i < st.len)
	{
		if (st.stack[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
