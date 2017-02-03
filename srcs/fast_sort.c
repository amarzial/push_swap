/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:55:34 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/03 21:42:05 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static size_t	max_index(t_stack *s)
{
	size_t	idx;
	size_t	i_max;
	int		max;
	t_list	*cur;

	idx = 0;
	cur = s->begin;
	max = LTOI(cur);
	i_max = 0;
	while (cur)
	{
		if (max < LTOI(cur))
		{
			max = LTOI(cur);
			i_max = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (i_max);
}

void		fast_sort(t_stack *a, t_stack *b, t_opts *opt)
{
	size_t pos;
	size_t size;

	pos = max_index(a);
	size = 3;
	if (pos == 0 && (size = 2))
		perform("ra", a, b, opt);
	else if (pos == 1 && (size = 2))
	{
		perform("ra", a, b, opt);
		perform("ra", a, b, opt);
	}
	lower(a, b, size, opt);
}
