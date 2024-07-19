/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.5sorting_giganumbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:11:14 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 13:51:09 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_more_v2(t_stack *a, t_stack *b)
{
	int	i;
	int	last;

	i = a->first;
	last = i;
	rotate(a, 1, 'a');
	while (a->first != i)
	{
		if (a->first > last)
		{
			last = a->first;
			rotate(a, 1, 'a');
		}
		else
			push(b, a, 1, 'b');
	}
	sort_back_to_a(a, b);
}
