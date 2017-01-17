/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:04:03 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/21 08:36:35 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static long double	fetch(t_arg *arg, va_list *lst)
{
	long double	num;
	num = va_arg(*lst, long double);
	if (arg->length_mod == L)
		return (num);
	else
		return ((double)num);
}

int		ft_printf_double(t_arg *arg, va_list *lst)
{
	long double	num;

	num = fetch(arg, lst);

}
