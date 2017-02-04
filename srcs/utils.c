/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:36:11 by amarzial          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/28 00:05:10 by amarzial         ###   ########.fr       */
=======
/*   Updated: 2017/02/04 03:02:25 by amarzial         ###   ########.fr       */
>>>>>>> b15e583a2397d458e324c44126da459f90408b01
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "stdint.h"
#include "mystack.h"
#include "push_swap.h"
#include "libft.h"
#include <stdint.h>
#include <limits.h>

int		validarg(const char *arg, t_stack *stack)
{
	intmax_t	num;
	t_list		*cursor;

	num = ft_atoi2(arg);
	if (num < INT_MIN || num > INT_MAX)
		error_exit(stack);
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

int		perform(char *op, t_stack *a, t_stack *b, t_opts *opt)
{
	if (exec_cmd(op, a, b))
	{
		ft_putstr(op);
		ft_putchar('\n');
		if (opt->verbose)
			print_status(a, b);
		return (1);
	}
	return (0);
}

t_stack	*stack_push_back(t_stack *stack, void *value, size_t size)
{
	t_list	*tmp;

	if (!stack->begin)
		return (stack_push(stack, value, size));
	if (!(tmp = ft_lstnew(value, size)))
		error_exit(stack);
	stack->end->next = tmp;
	stack->end = stack->end->next;
	return (stack);
}
