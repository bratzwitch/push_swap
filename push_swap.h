/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:34:19 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/17 16:35:24 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./lib_ft/includes/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	*data;
	int	size;
	int	top;
}		t_stack;

void	instructions(t_stack *a, t_stack *b);
void	init_stack(t_stack *stack, int size);
void	push(t_stack *stack, int value);
int	pop(t_stack *stack);
void	print_stack(t_stack *stack);
void	swap(int *a, int *b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);

#endif