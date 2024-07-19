/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.4sorting_5_or_less_num.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:57:23 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:08:08 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_top(t_stack *st, char st_name)
{
	int	min_pos;

	min_pos = get_pos(*st, get_min(*st)) + 1;
	if ((min_pos) / (double)st->len < 0.5)
	{
		while (min_pos)
		{
			rev_rotate(st, 1, st_name);
			min_pos--;
		}
	}
	else
	{
		min_pos = st->len - min_pos;
		while (min_pos)
		{
			rotate(st, 1, st_name);
			min_pos--;
		}
	}
}

void	sort_more_v1(t_stack *a, t_stack *b)
{
	while (a->len > 3)
		push(b, a, 1, 'b');
	sort_3(a);
	sort_back_to_a(a, b);
}

void	sort_back_to_a(t_stack *a, t_stack *b)
{
	int	best_insert;
	int	insert_pos;

	while (b->len)
	{
		best_insert = get_best_insert(*a, *b);
		insert_pos = get_insert_pos(*a, best_insert);
		rotate_both(a, insert_pos, b, get_pos(*b, best_insert) + 1);
		push(a, b, 1, 'a');
	}
	min_top(a, 'a');
}
