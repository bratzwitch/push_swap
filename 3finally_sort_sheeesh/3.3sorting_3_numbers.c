/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.3sorting_3_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:41:55 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:07:54 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->stack[2] > a->stack[1] && a->stack[1] < a->stack[0]
		&& a->stack[2] > a->stack[0])
		rotate(a, 1, 'a');
	if (a->stack[2] > a->stack[1] && a->stack[1] > a->stack[0])
		rotate(a, 1, 'a');
	if (a->stack[1] > a->stack[0])
		rev_rotate(a, 1, 'a');
	if (a->stack[2] > a->stack[1])
		swap(a, 1, 'a');
}
