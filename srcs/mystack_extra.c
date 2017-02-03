/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystack_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:38:39 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/03 13:57:35 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "mystack.h"

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
		sum += *(int*)lst->content;
		lst = lst->next;
		cnt--;
	}
	return (sum / (intmax_t)size);
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
			if (*(int*)cur->content > *(int*)med->content)
				curs[3]++;
			else if (*(int*)cur->content <= *(int*)med->content)
				curs[2]++;
			cur = cur->next;
		}
		if ((curs[2] - curs[3] == 0) || (curs[2] - curs[3] == 1))
			return (*(int*)med->content);
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
