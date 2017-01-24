/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:48:26 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/24 19:22:46 by amarzial         ###   ########.fr       */
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

static void	putarg(const char *arg, t_stack *stack)
{
	char	**tbl;
	int		cur;
	int		n;

	if (!(tbl = ft_strsplit(arg, ' ')))
		error_exit(stack);
	cur = 0;
	while (tbl[cur])
	{
		n = validarg(tbl[cur], stack);
		stack_push_back(stack, &n, sizeof(int));
		cur++;
	}
}

int			main(int argc, const char *argv[])
{
	int				i;
	static t_opts	opt;
	t_stack			stack[2];

	ft_bzero(stack, sizeof(t_stack) * 2);
	opt_parse(argc, argv, &opt);
	i = opt.size + 1;
	while (i < argc)
		putarg(argv[i++], stack);
	if (stack_size(stack) > 1)
		sort_stack(stack, stack + 1, &opt);
	empty_stack(stack);
	empty_stack(stack + 1);
	return (0);
}
