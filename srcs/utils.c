/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:36:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 20:04:20 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "stdint.h"
#include "mystack.h"
#include "push_swap.h"
#include "libft.h"
#include <stdint.h>
#include <limits.h>

int			validarg(const char *arg, t_stack *stack)
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

void		error_exit(t_stack *stack)
{
	stack_clear(stack);
	stack_clear(stack + 1);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static char	*next_cmd(t_stack *cmds)
{
	char	*op;

	op = (char*)stack_pop(cmds);
	if ((!ft_strcmp(op, "ra") && \
	!ft_strcmp((char*)cmds->begin->content, "rra")) || \
	(!ft_strcmp(op, "rb") && !ft_strcmp((char*)cmds->begin->content, "rrb")) ||
	(!ft_strcmp(op, "rra") && \
	!ft_strcmp((char*)cmds->begin->content, "ra")) || \
	(!ft_strcmp(op, "rrb") && !ft_strcmp((char*)cmds->begin->content, "rb")))
	{
		free(op);
		free(stack_pop(cmds));
		return (0);
	}
	return (op);
}

int			perform(char *op, t_stack *a, t_stack *b, t_opts *opt)
{
	static t_stack	commands;
	char			*cmd;

	if (opt->flush == 1)
	{
		opt->flush = 2;
		while (commands.begin)
		{
			if (!(cmd = next_cmd(&commands)))
				continue ;
			perform(cmd, a, b, opt);
			free(cmd);
		}
		opt->flush = 1;
		return (1);
	}
	else if (exec_cmd(op, a, b))
	{
		if (opt->flush == 2)
			print_special(op, a, b, opt);
		else
			stack_push_back(&commands, (void*)op, ft_strlen(op) + 1);
		return (1);
	}
	return (0);
}

t_stack		*stack_push_back(t_stack *stack, void *value, size_t size)
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
