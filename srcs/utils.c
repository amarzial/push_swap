/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:36:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/21 17:31:32 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"
#include "push_swap.h"
#include "libft.h"

int		validarg(const char *arg, t_stack *stack)
{
	int		num;
	t_list	*cursor;

	num = ft_atoi(arg);
	if ((num <= 0 && *arg == '-') || (num >= 0 && *arg == '+'))
		arg++;
	while (*arg)
		if (!ft_isdigit(*arg++))
			error_exit(stack);
	cursor = stack->begin;
	while (cursor)
	{
		if (num == *(int*)cursor->content)
			error_exit(stack);
		cursor = cursor->next;
	}
	return (num);
}

void	error_exit(t_stack *stack)
{
	stack_clear(stack);
	stack_clear(stack + 1);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	stack_limits(t_stack *stack, int *lims)
{
	t_list	*cur;

	cur = stack->begin;
	lims[0] = *(int*)cur->content;
	lims[1] = *(int*)cur->content;
	while (cur)
	{
		lims[0] = ft_min(lims[0], *(int*)cur->content);
		lims[1] = ft_max(lims[1], *(int*)cur->content);
		cur = cur->next;
	}
}
