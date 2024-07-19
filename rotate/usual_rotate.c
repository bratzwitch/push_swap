/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:29:21 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:08:32 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *st, int trigger, char st_name)
{
	int	first;
	int	i;

	if (st->len > 1)
	{
		i = st->len - 1;
		first = st->stack[st->len - 1];
		while (i > 0)
		{
			st->stack[i] = st->stack[i - 1];
			i--;
		}
		st->stack[0] = first;
	}
	st->first = st->stack[st->len - 1];
	if (trigger)
		ft_printf("r%c\n", st_name);
}
// blyat