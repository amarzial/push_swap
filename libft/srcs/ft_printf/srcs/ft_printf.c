/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:35:30 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/13 21:51:50 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static int	print_arg(char **str, va_list *lst)
{
	t_arg	arg;
	int		len;

	ft_bzero(&arg, sizeof(t_arg));
	len = ft_printf_parse_arg(*str, &arg, lst);
	ft_printf_handler(&arg, lst);
	*str += len;
	return (arg.size);
}

int			ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*cursor;
	int			out;

	cursor = (char*)format;
	out = 0;
	va_start(lst, format);
	while (*cursor)
	{
		if (*cursor == '%')
			out += print_arg(&cursor, &lst);
		else
		{
			ft_putchar(*cursor++);
			out++;
		}
	}
	va_end(lst);
	return (out);
}
