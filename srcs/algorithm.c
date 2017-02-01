/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/01 17:50:55 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static void		set_top(t_stack *stack, size_t size, t_select sel, t_opts *opt)
{
	char	*act;
	t_stack	*cmp;

	cmp = stack;
	if (sel == A)
		act = "sa";
	else
	{
		cmp = stack + 1;
		act = "sb";
	}
	if (size == 2 && (LTOI(cmp->begin) > LTOI(cmp->begin->next)))
		perform(act, stack, stack + 1, opt);
}

static void		merge_btoa(t_algo *vars, t_opts *opt)
{
	size_t	count;
	size_t	a_size;
	size_t	b_size;

	a_size = vars->a_size;
	b_size = vars->b_size;
	count = 0;
	while (b_size)
	{
		if (LTOI(vars->a->begin) < LTOI(vars->b->begin) && ++count)
			perform("ra", vars->a, vars->b, opt);
		if (((LTOI(vars->a->begin) > LTOI(vars->b->begin)) || \
		(count == a_size)) && ++a_size && b_size--)
			perform("pa", vars->a, vars->b, opt);
	}
	if (count && a_size == stack_size(vars->a) && count > a_size / 2)
		while (count++ < a_size)
			perform("ra", vars->a, vars->b, opt);
	else
		while (count--)
			perform("rra", vars->a, vars->b, opt);
}

static void		merge_atob(t_algo *vars, t_opts *opt)
{
	size_t	count;
	size_t	a_size;
	size_t	b_size;

	a_size = vars->a_size;
	b_size = vars->b_size;
	count = 0;
	while (a_size)
	{
		if (LTOI(vars->b->begin) < LTOI(vars->a->begin) && ++count)
			perform("rb", vars->a, vars->b, opt);
		if (((LTOI(vars->b->begin) > LTOI(vars->a->begin)) || \
		(count == b_size)) && ++b_size && a_size--)
			perform("pb", vars->a, vars->b, opt);
	}
	if (count && b_size == stack_size(vars->b) && count > b_size / 2)
		while (count++ < b_size)
			perform("rb", vars->a, vars->b, opt);
	else
		while (count--)
			perform("rrb", vars->a, vars->b, opt);
}

void			upper(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo vars;

	if (size <= 2)
	{
		set_top(a, size, B, opt);
		return ;
	}
	ft_bzero(&vars, sizeof(t_algo));
	vars.a = a;
	vars.b = b;
	while (vars.cnt++ < size / 2)
		perform("pa", a, b, opt);
	vars.b_size = size - (vars.cnt - 1);
	vars.a_size = (vars.cnt - 1);
	if (!stack_is_nsorted(a, vars.a_size))
		lower(a, b, vars.a_size, opt);
	if (!stack_is_nsorted(b, vars.b_size))
		upper(a, b, vars.b_size, opt);
	vars.sel = B;
	merge_atob(&vars, opt);
}

void			lower(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo	vars;

	if (size <= 2)
	{
		set_top(a, size, A, opt);
		return ;
	}
	ft_bzero(&vars, sizeof(t_algo));
	vars.a = a;
	vars.b = b;
	while (vars.cnt++ < size / 2)
		perform("pb", a, b, opt);
	vars.a_size = size - (vars.cnt - 1);
	vars.b_size = (vars.cnt - 1);
	if (!stack_is_nsorted(a, vars.a_size))
		lower(a, b, vars.a_size, opt);
	if (!stack_is_nsorted(b, vars.b_size))
		upper(a, b, vars.b_size, opt);
	vars.sel = A;
	merge_btoa(&vars, opt);
}

void			sort_stack(t_stack *a, t_stack *b, t_opts *opt)
{
	size_t	size;

	size = stack_size(a);
	if (size == 1)
		return ;
	lower(a, b, size, opt);
}
