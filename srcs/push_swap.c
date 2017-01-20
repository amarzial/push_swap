/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:48:26 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/20 16:04:43 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mystack.h"
#include "libft.h"

static void	empty_stack(t_stack *stack)
{
	if (!stack->begin)
		return ;
	while (stack->begin)
		free(stack_pop(stack));
}

static void	perform(char *op, t_stack *a, t_stack *b)
{
	if (exec_cmd(op, a, b))
	{
		ft_putstr(op);
		ft_putchar('\n');
	}
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	int		max;
	int		min;
	int		top;

	while (stack_size(a) > 2)
		perform("pb", a, b);
	max = ft_max(*(int*)a->begin->content, *(int*)a->end->content);
	min = ft_min(*(int*)a->begin->content, *(int*)a->end->content);
	while (b->begin)
	{
		top = *(int*)b->begin->content;
		if (top > min && top < max)
			while (!(*(int*)a->begin->content > top && \
			*(int*)a->end->content < top))
				perform("ra", a, b);
		else if (top > max && ((max = top) || 1))
			while (*(int*)a->begin->content != min)
				perform("ra", a, b);
		else if (top < min && ((min = top) || 1))
			while (*(int*)a->end->content != max)
				perform("ra", a, b);
		perform("pa", a, b);
	}
}

int			main(int argc, const char *argv[])
{
	int		i;
	int		n;
	t_stack	stack[2];

	ft_bzero(stack, sizeof(t_stack) * 2);
	i = argc - 1;
	while (i)
	{
		n = validarg(argv[i], stack);
		stack_push(stack, &n, sizeof(int));
		i--;
	}
	if (stack_size(stack) > 1)
		sort_stack(stack, stack + 1);
	empty_stack(stack);
	empty_stack(stack + 1);
	return (0);
}
