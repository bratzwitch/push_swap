/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.1stack_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:42:53 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:09:24 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	make_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		num_digit;
	int		fill_return;

	num_digit = number_of_digits(argc, argv);
	a->len = num_digit;
	a->stack = malloc(sizeof(int) * num_digit);
	if (!a->stack)
		exit(EXIT_FAILURE);
	b->len = 0;
	b->stack = malloc(sizeof(int) * num_digit);
	if (!b->stack)
	{
		free(a->stack);
		exit(EXIT_FAILURE);
	}
	if (!is_digit_argv(argc, argv))
		return (0);
	fill_return = fill_stack(a, num_digit, argv);
	if (fill_return == -1)
	{
		free(a->stack);
		free(b->stack);
		exit(EXIT_FAILURE);
	}
	return (fill_return);
}
