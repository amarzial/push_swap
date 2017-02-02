/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/01 19:35:17 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static void		set_top(t_algo *vars, size_t size, t_opts *opt)
{
	char	*act;
	t_stack	*cmp;

	if (vars->sel == A)
	{
		cmp = vars->a;
		act = "sa";
	}
	else
	{
		cmp = vars->b;
		act = "sb";
	}
	if (size == 2 && (LTOI(cmp->begin) > LTOI(cmp->begin->next)))
		perform(act, vars->a, vars->b, opt);
}

static void		heuristic(t_algo *vars, size_t size, t_opts *opt)
{
	if (size <= 2)
		set_top(vars, size, opt);
	else if (size <= 3)
		mysort(vars, size, opt);
}

void			upper(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo	vars;
	size_t	cnt;

	vars.a = a;
	vars.b = b;
	vars.sel = B;
	if (size <= 2)
	{
		heuristic(&vars, size, opt);
		return ;
	}
	cnt = 0;
	while (cnt++ < size / 2)
		perform("pa", a, b, opt);
	vars.b_size = size - (cnt - 1);
	vars.a_size = (cnt - 1);
	if (!stack_is_nsorted(a, vars.a_size))
		lower(a, b, vars.a_size, opt);
	if (!stack_is_nsorted(b, vars.b_size))
		upper(a, b, vars.b_size, opt);
	merge_atob(&vars, opt);
}

void			lower(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo	vars;
	size_t	cnt;

	vars.a = a;
	vars.b = b;
	vars.sel = A;
	if (size <= 2)
	{
		heuristic(&vars, size, opt);
		return ;
	}
	cnt = 0;
	while (cnt++ < size / 2)
		perform("pb", a, b, opt);
	vars.a_size = size - (cnt - 1);
	vars.b_size = (cnt - 1);
	if (!stack_is_nsorted(a, vars.a_size))
		lower(a, b, vars.a_size, opt);
	if (!stack_is_nsorted(b, vars.b_size))
		upper(a, b, vars.b_size, opt);
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
