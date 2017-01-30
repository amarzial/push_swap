/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:22:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/30 23:47:00 by amarzial         ###   ########.fr       */
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

	ft_printf("set_top: size=%lu, selected=%d\n", size, select);
	if (select == 0)
		act = "sa";
	else
		act = "sb";
	if (size == 2 && \
	(*(int*)stack->begin->content > *(int*)stack->begin->next->content))
		perform(act, stack, stack + 1, opt);
}

void			upper(t_stack *a, t_stack *b, size_t size, t_opts *opt)
{
	t_algo vars;

	if (size <= 2)
	{
		return ;
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
	
}

void			sort_stack(t_stack *a, t_stack *b, t_opts *opt)
{
	size_t	size;

	size = stack_size(a);
	if (size == 1)
		return ;
	lower(a, b, size, opt);
}
