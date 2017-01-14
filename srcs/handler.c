/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:19:23 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/13 22:39:07 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"

static int	swap(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "sa"))
		stack_swap(a);
	else if (!ft_strcmp(cmd, "sb"))
		stack_swap(b);
	else if (!ft_strcmp(cmd, "ss"))
	{
		stack_swap(a);
		stack_swap(b);
	}
	else
		return (0);
	return (1);
}

static int	push(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "pa"))
		stack_move(a, b);
	else if (!ft_strcmp(cmd, "pb"))
		stack_move(b, a);
	else
		return (0);
	return (1);
}

static int	rotate(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "ra"))
		stack_rotate(a);
	else if (!ft_strcmp(cmd, "rb"))
		stack_rotate(b);
	else if (!ft_strcmp(cmd, "rr"))
	{
		stack_rotate(a);
		stack_rotate(b);
	}
	else if (!ft_strcmp(cmd, "rra"))
		stack_rev_rotate(a);
	else if (!ft_strcmp(cmd, "rrb"))
		stack_rev_rotate(b);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		stack_rev_rotate(a);
		stack_rev_rotate(b);
	}
	else
		return (0);
	return (1);
}

int			exec_cmd(char *cmd, t_stack *a, t_stack *b)
{
	if (*cmd == 's')
		return (swap(cmd, a, b));
	else if (*cmd == 'p')
		return (push(cmd, a, b));
	else if (*cmd == 'r')
		return (rotate(cmd, a, b));
	return (0);
}
