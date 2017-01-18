/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:13:27 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/18 19:42:32 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mystack.h"
#include "libft.h"

static int	process_input(int fd, t_stack *a, t_stack *b)
{
	char	*line;
	int		status;

	while (ft_get_line(fd, &line) > 0)
	{
		status = exec_cmd(line, a, b);
		free(line);
		if (status == 0)
			return (0);
	}
	return (1);
}

int			main(int argc, const char *argv[])
{
	int		i;
	int		n;
	t_stack	stack[2];

	ft_bzero(stack, sizeof(t_stack) * 2);
	i = argc - 1;
	while (i)
	{
		n = validarg(argv[i], stack);
		stack_push(stack, &n, sizeof(int));
		i--;
	}
	if (!process_input(0, stack, stack + 1))
		error_exit(stack);
	if (stack_is_sorted(stack) && !(stack + 1)->begin)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(stack);
	stack_clear(stack + 1);
	return 0;
}
