/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   "3.4.1"insert_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:00:19 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/08 12:01:55 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max(t_stack st)
{
	int	i;
	int	max;

	i = 0;
	max = st.stack[i];
	while (i < st.len)
	{
		if (st.stack[i] > max)
			max = st.stack[i];
		i++;
	}
	return (max);
}

int	get_min(t_stack st)
{
	int	i;
	int	min;

	i = 0;
	min = st.stack[i];
	while (i < st.len)
	{
		if (st.stack[i] < min)
			min = st.stack[i];
		i++;
	}
	return (min);
}

int	get_insert_pos(t_stack st, int num)
{
	int	i;
	int	before;
	int	after;

	i = 0;
	while (i < st.len)
	{
		before = st.stack[i];
		if (i == 0)
			after = st.stack[st.len - 1];
		else
			after = st.stack[i - 1];
		if (num > get_max(st) && before == get_max(st))
			return (i);
		else if (num < get_min(st) && after == get_min(st))
			return (i);
		else if (num > before && num < after)
			return (i);
		i++;
	}
	return (-1);
}

int	get_best_insert(t_stack a, t_stack b)
{
	int	num_op;
	int	best;
	int	best_op;
	int	i;

	best = -1;
	best_op = -1;
	i = 0;
	while (i < b.len)
	{
		num_op = get_insert_pos(a, b.stack[b.len - 1 - i]);
		if ((num_op) / (double)a.len >= 0.5)
			num_op = a.len - num_op;
		if (i / (double)b.len < 0.5)
			num_op += i;
		else
			num_op += (b.len - i);
		if (best_op < 0 || num_op < best_op)
		{
			best_op = num_op;
			best = b.stack[b.len - 1 - i];
		}
		i++;
	}
	return (best);
}
