/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:43:49 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:11:12 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate(t_stack *st, int trigger, char st_name)
{
	int	last;
	int	i;

	if (st->len > 1)
	{
		i = 0;
		last = st->stack[0];
		while (i < st->len - 1)
		{
			st->stack[i] = st->stack[i + 1];
			i++;
		}
		st->stack[st->len - 1] = last;
	}
	st->first = st->stack[st->len - 1];
	if (trigger)
		ft_printf("rr%c\n", st_name);
}

void	rrotate(t_stack *s1, t_stack *s2, int trigger)
{
	rotate(s1, 0, 'a');
	rotate(s2, 0, 'b');
	if (trigger)
		ft_printf("rr\n");
}

void	rrev_rotate(t_stack *s1, t_stack *s2, int trigger)
{
	rev_rotate(s1, 0, 'a');
	rev_rotate(s2, 0, 'b');
	if (trigger)
		ft_printf("rrr\n");
}
