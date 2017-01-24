/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/24 20:05:56 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"
/*
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
*/
void			sort_stack(t_stack *a, t_stack *b, t_opts *opt)
{

	(void)a;
	(void)b;
	(void)opt;
}
