/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:21:59 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/25 18:43:12 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"
#include "bonus.h"
#include "libft.h"

void	opt_parse(int argc, const char *argv[], t_opts *opt)
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

void	print_status(t_stack *a, t_stack *b)
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
