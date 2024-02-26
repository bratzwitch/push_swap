/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:07:25 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/17 16:50:45 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_stack(t_stack *stack, int size)
{
	stack->data = malloc(sizeof(int) * size);
	if (stack->data == NULL)
	{
		ft_printf("Error: Memory allocation failed\n");
        return;
    }
	stack->size = size;
	stack->top = -1;
}

void	push(t_stack *stack, int value)
{
	if (stack->top == stack->size - 1)
		return ;
    if (stack->top < stack->size - 1)
    {
        ft_printf("%s","Error\n");
        return;
    }
	stack->data[++stack->top] = value;
}

int	pop(t_stack *stack)
{
	if (stack->top == -1)
		return (-1);
	return (stack->data[stack->top--]);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("%d ", stack->data[i]);
		i--;
	}
	ft_printf("\n");
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack *stack)
{
	if (stack->top >= 1)
	{
		swap(&stack->data[stack->top - 1], &stack->data[stack->top]);
		ft_printf("sa\n");
	}
}

void	sb(t_stack *stack)
{
	if (stack->top >= 1)
	{
		swap(&stack->data[stack->top - 1], &stack->data[stack->top]);
		ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top >= 0)
	{
		push(a, pop(b));
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top >= 0)
	{
		push(b, pop(a));
		ft_printf("pb\n");
	}
}

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top >= 1)
	{
		tmp = stack->data[stack->top];
		i = stack->top - 1;
		while (i >= 0)
		{
			stack->data[i + 1] = stack->data[i];
			i--;
		}
		stack->data[0] = tmp;
		ft_printf("ra\n");
	}
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top >= 1)
	{
		tmp = stack->data[stack->top];
		i = stack->top - 1;
		while (i >= 0)
		{
			stack->data[i + 1] = stack->data[i];
			i--;
		}
		stack->data[0] = tmp;
		ft_printf("rb\n");
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top >= 1)
	{
		tmp = stack->data[0];
		i = 1;
		while (i <= stack->top)
		{
			stack->data[i - 1] = stack->data[i];
			i++;
		}
		stack->data[stack->top] = tmp;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top >= 1)
	{
		tmp = stack->data[0];
		i = 1;
		while (i <= stack->top)
		{
			stack->data[i - 1] = stack->data[i];
			i++;
		}
		stack->data[stack->top] = tmp;
		ft_printf("rrb\n");
	}
}

void	instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		i;

	line = NULL;
	while (get_next_line(0) > 0)
	{
		i = 0;
		free(line);
		line = get_next_line(0);
		while (line[i])
		{
			if (line[i] == 's' && line[i + 1] == 'a')
				sa(a);
			else if (line[i] == 's' && line[i + 1] == 'b')
				sb(b);
			else if (line[i] == 's' && line[i + 1] == 's')
				ss(a, b);
			else if (line[i] == 'p' && line[i + 1] == 'a')
				pa(a, b);
			else if (line[i] == 'p' && line[i + 1] == 'b')
				pb(a, b);
			else if (line[i] == 'r' && line[i + 1] == 'a')
				ra(a);
			else if (line[i] == 'r' && line[i + 1] == 'b')
				rb(b);
			else if (line[i] == 'r' && line[i + 1] == 'r')
				rr(a, b);
			else if (line[i] == 'r' && line[i + 1] == 'r' && line[i + 2] == 'a')
				rra(a);
			else if (line[i] == 'r' && line[i + 1] == 'r' && line[i + 2] == 'b')
				rrb(b);
			i++;
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (argc < 2)
		return (1);
	i = 1;
	init_stack(&a, argc - 1);
	while (i < argc)
	{
		push(&a, atoi(argv[i]));
		i++;
	}
	init_stack(&b, 0);
	instructions(&a, &b);
	return (0);
}
