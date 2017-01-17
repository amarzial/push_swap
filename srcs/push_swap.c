/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:48:26 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/16 16:28:31 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mystack.h"
#include "libft.h"

static void	empty_stack(t_stack *stack)
{
	if (!stack->begin)
		return ;
	while (stack->begin)
		free(stack_pop(stack));
}

static void	perform(char *op, t_stack *a, t_stack *b)
{
	if (exec_cmd(op, a, b))
	{
		ft_printf("%s\n", op);
	}
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	while (stack_size(a) > 2)
		perform("pb", a, b);
	while (b->begin)
	{
		while (*(int*)b->begin->content > *(int*)a->begin->content)
		{
			if (stack_is_sorted(a) && \
			*(int*)b->begin->content > *(int*)a->end->content)
				break ;
			perform("ra", a, b);
		}
		perform ("pa", a, b);
	}
}

int		main(int argc, const char *argv[])
{
	int		i;
	int		n;
	t_stack	stack;
	t_stack	stack2;

	ft_bzero(&stack, sizeof(t_stack));
	ft_bzero(&stack2, sizeof(t_stack));
	i = argc - 1;
	while (i)
	{
		n = ft_atoi(argv[i]);
		stack_push(&stack, &n, sizeof(int));
		i--;
	}
	sort_stack(&stack, &stack2);
	empty_stack(&stack);
	empty_stack(&stack2);
	return 0;
}
