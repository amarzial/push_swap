/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:00:55 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/01 15:45:15 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*get_op(char *op, t_select selected)
{
	char *stack;

	stack = (selected == A) ? "a" : "b";
	return (ft_strjoin(op, stack));
}
