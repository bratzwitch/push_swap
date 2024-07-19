/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:34:19 by vmoroz            #+#    #+#             */
/*   Updated: 2024/07/19 14:10:57 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib_ft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_stack
{
	int	*stack;
	int	first;
	int	len;
}		t_stack;

void	swap(t_stack *st, int trigger, char st_name);
void	sswap(t_stack *s1, t_stack *s2, int trigger);
void	push(t_stack *a, t_stack *b, int trigger, char st_name);
void	rotate(t_stack *st, int trigger, char st_name);
void	rrotate(t_stack *s1, t_stack *s2, int trigger);
void	rev_rotate(t_stack *st, int trigger, char st_name);
void	rrev_rotate(t_stack *s1, t_stack *s2, int trigger);
int		get_max(t_stack st);
int		get_min(t_stack st);
int		get_pos(t_stack st, int num);
int		is_sorted(t_stack st);
void	rotate_both(t_stack *a, int a_top, t_stack *b, int b_top);
int		get_insert_pos(t_stack st, int num);
void	min_top(t_stack *st, char st_name);
int		get_best_insert(t_stack a, t_stack b);
int		count_kept_in_a(t_stack a, int num);
void	sort(t_stack *a, t_stack *b);
int		make_stacks(t_stack *a, t_stack *b, int argc, char **argv);
int		fill_stack(t_stack *a, int num_digit, char **argv);
int		number_of_digits(int argc, char **argv);
long	atol(const char *str);
int		find_duplicates(t_stack st);
int		is_digit_str(char *str);
int		is_digit_argv(int argc, char **argv);
void	sort_3(t_stack *a);
void	sort_more_v2(t_stack *a, t_stack *b);
void	sort_more_v1(t_stack *a, t_stack *b);
void	sort_back_to_a(t_stack *a, t_stack *b);

#endif