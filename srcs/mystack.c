/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:57:09 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/29 20:08:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"
#include "libft.h"

void	stack_move(t_stack *dest, t_stack *src)
{
	t_list	*tmp;

	if (src->begin)
	{
		if (src->begin == src->end)
			src->end = 0;
		tmp = src->begin;
		src->begin = src->begin->next;
		ft_lstadd(&dest->begin, tmp);
		if (dest->end == 0)
			dest->end = dest->begin;
	}
}

void	stack_rotate(t_stack *stack)
{
	t_list	*tmp;

	if (stack->begin && stack->begin->next)
	{
		tmp = stack->begin;
		stack->begin = stack->begin->next;
		tmp->next = 0;
		stack->end->next = tmp;
		stack->end = stack->end->next;
	}
}

void	stack_rev_rotate(t_stack *stack)
{
	t_list	*cur;

	if (stack->begin && stack->begin->next)
	{
		cur = stack->begin;
		while (cur->next != stack->end)
			cur = cur->next;
		stack->end->next = stack->begin;
		stack->begin = stack->end;
		cur->next = 0;
		stack->end = cur;
	}
}

void	stack_swap(t_stack *stack)
{
	t_list	*tmp;

	if (stack->begin && stack->begin->next)
	{
		tmp = stack->begin;
		stack->begin = stack->begin->next;
		tmp->next = stack->begin->next;
		stack->begin->next = tmp;
		if (stack->end == stack->begin)
			stack->end = tmp;
	}
}

int		stack_is_ordered(t_stack *stack)
{
	int		head;
	int		min;
	t_list	*cur;

	if (stack_size(stack) <= 2)
		return (1);
	cur = stack->begin;
	head = 0;
	min = *(int*)cur->content;
	while (cur != stack->end && head < 2)
	{
		if (*(int*)cur->content >= *(int*)cur->next->content)
			head++;
		if (head && *(int*)cur->content > min)
			return (0);
		cur = cur->next;
	}
	if (head == 1)
		return (1);
	return (0);
}
