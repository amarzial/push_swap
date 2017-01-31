/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/28 14:59:11 by amarzial         ###   ########.fr       */
=======
/*   Updated: 2017/01/30 23:47:00 by amarzial         ###   ########.fr       */
>>>>>>> 559b87e297cd0e835c6abe25c1fe71968b904cd3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include "push_swap.h"
#include "bonus.h"
#include "mystack.h"

static void		set_top(t_stack *stack, size_t size, int select, t_opts *opt)
{
	char	*act;

<<<<<<< HEAD
	sum = 0;
	lst = stack->begin;
	cnt = size;
	while (cnt)
	{
		sum += *(int*)lst->content;
		lst = lst->next;
		cnt--;
	}
	if (sum % 2)
		sum++;
	return (sum / (intmax_t)size);
=======
	ft_printf("set_top: size=%lu, selected=%d\n", size, select);
	if (select == 0)
		act = "sa";
	else
		act = "sb";
	if (size == 2 && \
	(*(int*)stack->begin->content > *(int*)stack->begin->next->content))
		perform(act, stack, stack + 1, opt);
>>>>>>> 559b87e297cd0e835c6abe25c1fe71968b904cd3
}

void			upper(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo vars;

	if (size <= 2)
	{
<<<<<<< HEAD
		if ((*(int*)b->begin->content >= vars.avg) && ((vars.splits[0]++) || 1))
			perform("pa", a, b, opt);
		else if ((vars.splits[1]++) || 1)
		{
			perform("rb", a, b, opt);
			vars.rot++;
		}
=======
		return ;
>>>>>>> 559b87e297cd0e835c6abe25c1fe71968b904cd3
	}
	ft_bzero(&vars, sizeof(t_algo));
	while (vars.cnt++ < size / 2)
		perform("pa", a, b, opt);
	lower(a, b, size - (vars.cnt - 1), opt);
	upper(a, b, vars.cnt - 1, opt);
}

void			lower(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo	vars;

<<<<<<< HEAD
	if (size <= 1 || stack_is_sorted(a))
		return ;
	ft_bzero(&vars, sizeof(t_algo));
	vars.avg = stack_avg(a, size);
	if (size == 2 && *(int*)a->begin->content > *(int*)a->begin->next->content)
		perform("sa", a, b, opt);
	else
		while (vars.cnt++ < size)
		{
			if ((*(int*)a->begin->content < vars.avg) && ((vars.splits[1]++) || 1))
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
=======
	if (size <= 2)
	{
		set_top(a, size, 0, opt);
		return ;
	}
	ft_bzero(&vars, sizeof(t_algo));
	while (vars.cnt++ < size / 2)
		perform("pb", a, b, opt);
	lower(a, b, size - (vars.cnt - 1), opt);
	upper(a, b, vars.cnt - 1, opt);
	
>>>>>>> 559b87e297cd0e835c6abe25c1fe71968b904cd3
}

void			sort_stack(t_stack *a, t_stack *b, t_opts *opt)
{
	size_t	size;

	size = stack_size(a);
	if (size == 1)
		return ;
	lower(a, b, size, opt);
}
