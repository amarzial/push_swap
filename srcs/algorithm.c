/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/24 14:42:10 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static int		place(t_stack *a, int top, int *lims)
{
	int		res;

	if ((top > lims[0] && top < lims[1]) && (*(int*)a->begin->content > top && \
		*(int*)a->end->content < top))
		res = 1;
	else if (top > lims[1] && (*(int*)a->begin->content == lims[0]))
		res = 1;
	else if (top < lims[0] && (*(int*)a->end->content == lims[1]))
		res = 1;
	else
		res = 0;
	if (res)
	{
		lims[0] = ft_min(top, lims[0]);
		lims[1] = ft_max(top, lims[1]);
	}
	return (res);
}

void			sort_stack(t_stack *a, t_stack *b, t_opts *opt)
{
	int		limits[2];

	while (stack_size(a) > 2 && !stack_is_ordered(a))
		perform("pb", a, b, opt);
	stack_limits(a, limits);
	while (b->begin)
	{
		if (place(a, *(int*)b->begin->content, limits))
		{
			perform("pa", a, b, opt);
			continue ;
		}
		else if (b->begin->next && \
				place(a, *(int*)b->begin->next->content, limits))
		{
			perform("sb", a, b, opt);
			perform("pa", a, b, opt);
			continue ;
		}
		perform("ra", a, b, opt);
	}
	while (*(int*)a->begin->content != limits[0])
		perform("ra", a, b, opt);
}
