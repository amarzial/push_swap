/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystack_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:38:39 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 19:41:36 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "mystack.h"
#include "push_swap.h"

static int		stack_avg(t_stack *stack, size_t size)
{
	intmax_t	sum;
	size_t		cnt;
	t_list		*lst;

	sum = 0;
	lst = stack->begin;
	cnt = size;
	while (cnt)
	{
		sum += LTOI(lst);
		lst = lst->next;
		cnt--;
	}
	return (sum / (intmax_t)size);
}

size_t			min_index(t_stack *s, size_t size)
{
	size_t	idx;
	size_t	i_min;
	int		min;
	t_list	*cur;

	idx = 0;
	cur = s->begin;
	min = LTOI(cur);
	i_min = 0;
	while (cur && size--)
	{
		if (min > LTOI(cur))
		{
			min = LTOI(cur);
			i_min = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (i_min);
}

size_t			max_index(t_stack *s, size_t size)
{
	size_t	idx;
	size_t	i_max;
	int		max;
	t_list	*cur;

	idx = 0;
	cur = s->begin;
	max = LTOI(cur);
	i_max = 0;
	while (cur && size--)
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

static int		stack_median(t_stack *stack, size_t size)
{
	size_t	curs[4];
	t_list	*cur;
	t_list	*med;

	med = stack->begin;
	curs[0] = size;
	while (curs[0]--)
	{
		ft_bzero(curs + 2, sizeof(size_t) * 2);
		curs[1] = size;
		cur = stack->begin;
		while (cur && curs[1]--)
		{
			if (LTOI(cur) > LTOI(med))
				curs[3]++;
			else if (LTOI(cur) <= LTOI(med))
				curs[2]++;
			cur = cur->next;
		}
		if ((curs[2] - curs[3] == 0) || (curs[2] - curs[3] == 1))
			return (LTOI(med));
		med = med->next;
	}
	return (0);
}

int				stack_pivot(t_stack *stack, size_t size)
{
	if (size <= 100)
		return (stack_median(stack, size));
	else
		return (stack_avg(stack, size));
}
