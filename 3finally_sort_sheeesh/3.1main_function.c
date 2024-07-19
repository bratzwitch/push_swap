/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1main_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:25:18 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:07:43 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_kept_in_a(t_stack a, int num)
{
	int	pos;
	int	total;
	int	i;

	total = 0;
	pos = get_pos(a, num);
	i = pos;
	while (i-- > 0)
	{
		if (a.stack[i] > num)
		{
			num = a.stack[i];
			total++;
		}
	}
	i = a.len - 1;
	while (i-- > pos)
	{
		if (a.stack[i] > num)
		{
			num = a.stack[i];
			total++;
		}
	}
	return (total);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(*a))
		return ;
	if (a->len == 2)
	{
		if (a->first > a->stack[0])
			rotate(a, 1, 'a');
	}
	else if (a->len <= 3)
		sort_3(a);
	else if (a->len <= 5)
		sort_more_v1(a, b);
	else
	{
		if (count_kept_in_a(*a, a->first) > 3)
			sort_more_v2(a, b);
		else
			sort_more_v1(a, b);
	}
}
