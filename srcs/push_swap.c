/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:48:26 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/15 21:16:59 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mystack.h"
#include "libft.h"

static int	is_sort(t_stack *stack)
{
	t_list	*tmp;

	if (stack->begin == stack->end)
		return (1);
	tmp = stack->begin;
	while (tmp != stack->end)
	{
		if (*(int*)tmp->content >= *(int*)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	print_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->begin;
	while (tmp)
	{
		ft_printf("%d ", *(int*)tmp->content);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
static void	status(t_stack *a, t_stack *b, size_t cnt)
{
	ft_printf("- %lu\nstack 1:\n", cnt);
	print_stack(a);
	ft_printf("stack 2:\n");
	print_stack(b);
	ft_printf("=======================\n");
}

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
			if (is_sort(a) && *(int*)b->begin->content > *(int*)a->end->content)
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
	size_t	count;
	char	*line;
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
