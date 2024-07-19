/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:33:10 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:08:47 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *st, int trigger, char st_name)
{
	int	temp;

	if (st->len > 1)
	{
		temp = st->stack[st->len - 1];
		st->stack[st->len - 1] = st->stack[st->len - 2];
		st->stack[st->len - 2] = temp;
	}
	st->first = st->stack[st->len - 1];
	if (trigger)
		ft_printf("s%c\n", st_name);
}
