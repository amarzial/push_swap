/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:21:59 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 20:19:16 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"
#include "bonus.h"
#include "libft.h"

void		opt_push_swap(int argc, const char *argv[], t_opts *opt)
{
	int		cur;

	cur = 1;
	while (cur < argc && argv[cur][0] == '-')
	{
		if (argv[cur][1] == 'v' && (opt->size++ || 1))
			opt->verbose = 1;
		else if (argv[cur][1] == 'c' && (opt->size++ || 1))
			opt->color = 1;
		else if (!ft_isdigit(argv[cur][1]))
		{
			ft_putstr_fd("Error: Unknown argument", 2);
			exit(2);
		}
		cur++;
	}
}

void		opt_checker(int argc, const char *argv[], t_opts *opt)
{
	int		cur;

	cur = 1;
	while (cur < argc && argv[cur][0] == '-')
	{
		if (argv[cur][1] == 'v' && (opt->size++ || 1))
			opt->verbose = 1;
		else if (argv[cur][1] == 'f' && (opt->size++ || 1))
		{
			opt->size++;
			if (cur + 1 >= argc || (opt->fd = open(argv[++cur], O_RDONLY)) < 0)
			{
				ft_printf_fd(2, "Error reading file \"%s\"", argv[cur]);
				exit(3);
			}
		}
		else if (!ft_isdigit(argv[cur][1]))
		{
			ft_putstr_fd("Error: Unknown argument", 2);
			exit(2);
		}
		cur++;
	}
}

static int	get_color(char *op)
{
	if (ft_strncmp(op, "rr", 2) == 0)
		return (93);
	else if (ft_strncmp(op, "r", 1) == 0)
		return (91);
	else if (ft_strncmp(op, "p", 1) == 0)
		return (92);
	else if (ft_strncmp(op, "s", 1) == 0)
		return (94);
	return (0);
}

void		print_special(char *op, t_stack *a, t_stack *b, t_opts *opt)
{
	char *col;

	if (opt->color)
	{
		col = ft_itoa(get_color(op));
		ft_printf("\x1B[%sm%s%s", col, op, FT_COL("0"));
		free(col);
	}
	else
		ft_putstr(op);
	ft_putchar('\n');
	if (opt->verbose)
		print_status(a, b);
}

void		print_status(t_stack *a, t_stack *b)
{
	t_list	*cur;

	ft_printf("stack a:\n");
	cur = a->begin;
	while (cur)
	{
		ft_printf("%d ", *(int*)cur->content);
		cur = cur->next;
	}
	ft_printf("\nstack b:\n");
	cur = b->begin;
	while (cur)
	{
		ft_printf("%d ", *(int*)cur->content);
		cur = cur->next;
	}
	ft_printf("\n\n");
}
