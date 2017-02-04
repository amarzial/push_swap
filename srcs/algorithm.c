/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 19:20:52 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static void		set_top(t_stack *stack, size_t size, t_select sel, t_opts *opt)
{
	if (size == 2)
	{
		if (sel == A && LTOI(stack->begin) > LTOI(stack->begin->next))
			perform("sa", stack, stack + 1, opt);
		else if (sel != A && LTOI(stack->begin) < LTOI(stack->begin->next))
			perform("sb", stack - 1, stack, opt);
	}
}

void			handler(t_stack *a, t_select sel, size_t size, t_opts *opt)
{
	if (sel == A)
	{
		if (size == 2)
			set_top(a, 2, A, opt);
		else if (size == 3)
			fast_sort(a, a + 1, A, opt);
	}
	else if (sel != A)
	{
		if (size == 2)
			set_top(a + 1, 2, B, opt);
		else if (size == 3)
			fast_sort(a, a + 1, B, opt);
		while (size--)
			perform("pa", a, a + 1, opt);
	}
}

void			upper(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo vars;

	if (size <= 3)
	{
		handler(a, B, size, opt);
		return ;
	}
	ft_bzero(&vars, sizeof(t_algo));
	vars.avg = stack_pivot(b, size);
	while (vars.cnt++ < size)
	{
		if ((LTOI(b->begin) > vars.avg) && ((vars.splits[0]++) || 1))
			perform("pa", a, b, opt);
		else if ((vars.splits[1]++) || 1)
		{
			perform("rb", a, b, opt);
			vars.rot++;
		}
	}
	vars.rot %= stack_size(b);
	while (vars.rot--)
		perform("rrb", a, b, opt);
	lower(a, b, vars.splits[0], opt);
	upper(a, b, vars.splits[1], opt);
}

void			lower(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo	vars;

	if (size <= 3 || stack_is_nsorted(a, size))
	{
		if (size <= 3)
			handler(a, A, size, opt);
		return ;
	}
	ft_bzero(&vars, sizeof(t_algo));
	vars.avg = stack_pivot(a, size);
	while (vars.cnt++ < size)
	{
		if ((LTOI(a->begin) <= vars.avg) && ((vars.splits[1]++) || 1))
			perform("pb", a, b, opt);
		else if ((vars.splits[0]++) || 1)
		{
			perform("ra", a, b, opt);
			vars.rot++;
		}
	}
	vars.rot %= stack_size(a);
	while (vars.rot--)
		perform("rra", a, b, opt);
	lower(a, b, vars.splits[0], opt);
	upper(a, b, vars.splits[1], opt);
}

void			sort_stack(t_stack *a, t_stack *b, t_opts *opt)
{
	size_t	size;

	size = stack_size(a);
	if (size == 1)
		return ;
	else if (size == 3)
		fast_sort(a, b, A, opt);
	else
		lower(a, b, size, opt);
}
