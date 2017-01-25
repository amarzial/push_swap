/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/25 16:36:09 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static int		stack_avg(t_stack *stack, size_t size)
{
	int		sum;
	size_t	cnt;
	t_list	*lst;

	sum = 0;
	lst = stack->begin;
	cnt = size;
	while (cnt)
	{
		sum += *(int*)lst->content;
		lst = lst->next;
		cnt--;
	}
	return (sum / size);
}

void			upper(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo vars;

	if (size <= 0)
		return ;
	if (size == 1 && perform("pa", a, b, opt))
		return ;
	ft_bzero(&vars, sizeof(t_algo));
	vars.avg = stack_avg(b, size);
	while (vars.cnt++ < size)
	{
		if ((*(int*)b->begin->content > vars.avg) && ((vars.splits[0]++) || 1))
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
	if (size <= 1)
		return ;
	ft_bzero(&vars, sizeof(t_algo));
	vars.avg = stack_avg(a, size);
	while (vars.cnt++ < size)
	{
		if ((*(int*)a->begin->content <= vars.avg) && ((vars.splits[1]++) || 1))
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
	lower(a, b, size, opt);
}
