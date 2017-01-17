/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_noconv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:27:12 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/18 20:40:35 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(t_arg *arg)
{
	char	fill;
	int		len;

	fill = arg->flag_zero ? '0' : ' ';
	len = 1;
	if (arg->prec_set && arg->precision > 1)
		len = ft_min(1, arg->precision);
	if (arg->field_width > 1)
	{
		if (arg->flag_left)
		{
			ft_putchar(arg->conversion);
			ft_printf_putnchar(fill, arg->field_width - len);
		}
		else
		{
			ft_printf_putnchar(fill, arg->field_width - len);
			ft_putchar(arg->conversion);
		}
	}
	else
		ft_putchar(arg->conversion);
	arg->size = ft_max(1, arg->field_width);
}

int				ft_printf_noconv(t_arg *arg, va_list *lst)
{
	(void)lst;
	padding(arg);
	return (1);
}
