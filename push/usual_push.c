/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:31:15 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/18 16:44:15 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *a, t_stack *b, int trigger, char st_name)
{
	if (b->len)
	{
		a->stack[a->len] = b->stack[b->len - 1];
		a->len++;
		b->len--;
		a->first = a->stack[a->len - 1];
		if (b->len)
			b->first = b->stack[b->len - 1];
		else
			b->first = -1;
	}
	if (trigger)
		ft_printf("p%c\n", st_name);
}
