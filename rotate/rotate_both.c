/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:02:46 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:10:26 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_rot(int *st_rot, int st_dir, int st_top, int st_len)
{
	*st_rot = st_top;
	if (!st_dir)
		*st_rot = st_len - st_top;
}

void	rotate_a_b(t_stack *a, int a_dir, t_stack *b, int b_dir)
{
	if (a_dir && b_dir)
		rrev_rotate(a, b, 1);
	else if (!a_dir && !b_dir)
		rrotate(a, b, 1);
	else if (a_dir && !b_dir)
	{
		rev_rotate(a, 1, 'a');
		rotate(b, 1, 'b');
	}
	else if (!a_dir && b_dir)
	{
		rotate(a, 1, 'a');
		rev_rotate(b, 1, 'b');
	}
}

void	rotate_st(t_stack *st, int st_dir, char st_name)
{
	if (st_dir)
		rev_rotate(st, 1, st_name);
	else
		rotate(st, 1, st_name);
}

void	rotate_both(t_stack *a, int a_top, t_stack *b, int b_top)
{
	int	a_dir;
	int	a_rot;
	int	b_dir;
	int	b_rot;

	a_dir = a_top / (double)a->len < 0.5;
	b_dir = b_top / (double)b->len < 0.5;
	set_rot(&a_rot, a_dir, a_top, a->len);
	set_rot(&b_rot, b_dir, b_top, b->len);
	while (a_rot || b_rot)
	{
		if (a_rot && b_rot)
			rotate_a_b(a, a_dir, b, b_dir);
		else if (a_rot)
			rotate_st(a, a_dir, 'a');
		else if (b_rot)
			rotate_st(b, b_dir, 'b');
		if (a_rot)
			a_rot--;
		if (b_rot)
			b_rot--;
	}
}
