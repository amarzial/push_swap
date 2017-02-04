/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystack_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:56:42 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 00:55:33 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"
#include "libft.h"

t_stack	*stack_push(t_stack *stack, void *value, size_t size)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(value, size)))
		return (0);
	tmp->next = stack->begin;
	stack->begin = tmp;
	if (!stack->end)
		stack->end = stack->begin;
	return (stack);
}

void	*stack_pop(t_stack *stack)
{
	t_list	*tmp;
	void	*content;

	if (stack->begin)
	{
		if (stack->end == stack->begin)
			stack->end = 0;
		tmp = stack->begin;
		stack->begin = stack->begin->next;
		content = tmp->content;
		free(tmp);
	}
	else
		return (0);
	return (content);
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;
	t_list	*cursor;

	if (!stack->begin)
		return (0);
	cursor = stack->begin;
	size = 1;
	while (cursor != stack->end)
	{
		cursor = cursor->next;
		size++;
	}
	return (size);
}

int		stack_is_sorted(t_stack *stack)
{
	t_list	*tmp;
	int		vals[2];

	if (stack->begin == stack->end)
		return (1);
	tmp = stack->begin;
	while (tmp != stack->end)
	{
		vals[0] = *(int*)tmp->content;
		vals[1] = *(int*)tmp->next->content;
		if (vals[0] >= vals[1])
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		stack_is_nsorted(t_stack *stack, size_t size)
{
	t_list	*tmp;
	int		vals[2];

	if (stack->begin == stack->end)
		return (1);
	tmp = stack->begin;
	while (tmp != stack->end && size--)
	{
		vals[0] = *(int*)tmp->content;
		vals[1] = *(int*)tmp->next->content;
		if (vals[0] >= vals[1])
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
