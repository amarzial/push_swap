/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:55:34 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 02:51:37 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static void	chunk(t_stack *a, t_stack *b, t_opts *opt)
{
	size_t pos;
	size_t size;

	size = 3;
	pos = max_index(a, size);
	if (pos == 0)
	{
		perform("sa", a, b, opt);
		perform("ra", a, b, opt);
		perform("sa", a, b, opt);
		perform("rra", a, b, opt);
	}
	else if (pos == 1 && (size = 2))
	{
		perform("ra", a, b, opt);
		perform("sa", a, b, opt);
		perform("rra", a, b, opt);
	}
	if (LTOI(a->begin) > LTOI(a->begin->next))
		perform("sa", a, b, opt);
}

static void	chunk_rev(t_stack *a, t_stack *b, t_opts *opt)
{
	size_t pos;
	size_t size;

	size = 3;
	pos = min_index(b, size);
	if (pos == 0)
	{
		perform("sb", a, b, opt);
		perform("rb", a, b, opt);
		perform("sb", a, b, opt);
		perform("rrb", a, b, opt);
	}
	else if (pos == 1 && (size = 2))
	{
		perform("rb", a, b, opt);
		perform("sb", a, b, opt);
		perform("rrb", a, b, opt);
	}
	if (LTOI(b->begin) < LTOI(b->begin->next))
		perform("sb", a, b, opt);
}

static void	size3(t_stack *a, t_stack *b, int rev, t_opts *opt)
{
	size_t pos;

	pos = (!rev) ? max_index(a, 3) : min_index(b, 3);
	if (!rev)
	{
		if (pos == 0)
			perform("ra", a, b, opt);
		else if (pos == 1)
		{
			perform("ra", a, b, opt);
			perform("ra", a, b, opt);
		}
		if (LTOI(a->begin) > LTOI(a->begin->next))
			perform("sa", a, b, opt);
		return ;
	}
	if (pos == 0)
		perform("rb", a, b, opt);
	else if (pos == 1)
		perform("rrb", a, b, opt);
	if (LTOI(b->begin) < LTOI(b->begin->next))
		perform("sb", a, b, opt);
}

void		fast_sort(t_stack *a, t_stack *b, t_select sel, t_opts *opt)
{
	if (sel == A)
	{
		if (stack_size(a) == 3)
			size3(a, b, 0, opt);
		else
			chunk(a, b, opt);
	}
	else
	{
		if (stack_size(b) == 3)
			size3(a, b, 1, opt);
		else
			chunk_rev(a, b, opt);
	}
}
