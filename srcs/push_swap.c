/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:48:26 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/20 20:42:34 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mystack.h"
#include "bonus.h"
#include "libft.h"

static void	empty_stack(t_stack *stack)
{
	if (!stack->begin)
		return ;
	while (stack->begin)
		free(stack_pop(stack));
}

static int	perform(char *op, t_stack *a, t_stack *b, t_opts *opt)
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

static int	place(t_stack *a, int top, int *lims)
{
	int		res;

	if ((top > lims[0] && top < lims[1]) && (*(int*)a->begin->content > top && \
		*(int*)a->end->content < top))
			res = 1;
	else if (top > lims[1] && (*(int*)a->begin->content == lims[0]))
			res = 1;
	else if (top < lims[0] && (*(int*)a->end->content == lims[1]))
			res = 1;
	else
		res = 0;
	if (res)
	{
		lims[0] = ft_min(top, lims[0]);
		lims[1] = ft_max(top, lims[1]);
	}
	return (res);
}

static void	sort_stack(t_stack *a, t_stack *b, t_opts *opt)
{
	int		limits[2];

	while (stack_size(a) > 2 && !stack_is_sorted(a))
		perform("pb", a, b, opt);
	limits[1] = ft_max(*(int*)a->begin->content, *(int*)a->end->content);
	limits[0] = ft_min(*(int*)a->begin->content, *(int*)a->end->content);
	while (b->begin)
	{
		if (place(a, *(int*)b->begin->content, limits))
		{
			perform("pa", a, b, opt);
			continue ;
		}
		else if (b->begin->next && \
				place(a, *(int*)b->begin->next->content, limits))
		{
			perform("sb", a, b, opt);
			perform("pa", a, b, opt);
			continue ;
		}
		perform("ra", a, b, opt);
	}
	while (*(int*)a->begin->content != limits[0])
		perform("ra", a, b, opt);
}

int			main(int argc, const char *argv[])
{
	int				i;
	int				n;
	static t_opts	opt;
	t_stack			stack[2];

	ft_bzero(stack, sizeof(t_stack) * 2);
	i = argc - 1;
	opt_parse(argc, argv, &opt);
	while (i > opt.size)
	{
		n = validarg(argv[i], stack);
		stack_push(stack, &n, sizeof(int));
		i--;
	}
	if (stack_size(stack) > 1)
		sort_stack(stack, stack + 1, &opt);
	empty_stack(stack);
	empty_stack(stack + 1);
	return (0);
}
