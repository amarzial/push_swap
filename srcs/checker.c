/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:13:27 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/25 18:30:53 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mystack.h"
#include "libft.h"

static int	process_input(int fd, t_stack *a, t_stack *b, t_opts *opt)
{
	char	*line;
	int		status;

	while (ft_get_line(fd, &line) > 0)
	{
		status = exec_cmd(line, a, b);
		if (opt->verbose)
		{
			ft_printf("%s :\n", line);
			print_status(a, b);
		}
		free(line);
		if (status == 0)
			return (0);
	}
	return (1);
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
	t_stack	stack[2];

	ft_bzero(stack, sizeof(t_stack) * 2);
	opt_parse(argc, argv, &opt);
	i = opt.size + 1;
	while (i < argc)
		putarg(argv[i++], stack);
	if (!process_input(0, stack, stack + 1, &opt))
		error_exit(stack);
	if (stack_is_sorted(stack) && !(stack + 1)->begin)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(stack);
	stack_clear(stack + 1);
	return (0);
}
