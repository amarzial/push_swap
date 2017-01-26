/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:21:40 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/26 12:22:26 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystack.h"
#include "push_swap.h"
#include "libft.h"

void	putarg(const char *arg, t_stack *stack)
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
        free(tbl[cur]);
		cur++;
	}
    free(tbl);
}
