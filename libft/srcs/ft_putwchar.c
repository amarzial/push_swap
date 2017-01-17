/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:00:42 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/17 20:24:04 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bitcount(wchar_t c)
{
	if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if (c >= 0x800 && c <= 0xFFFF)
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	else
		return (0);
}

static void	setmask(char *mask)
{
	mask[0] = 0x80;
	mask[1] = 0xC0;
	mask[2] = 0xE0;
	mask[3] = 0xF0;
	mask[4] = 0x3F;
	mask[5] = 0x1F;
	mask[6] = 0x0F;
	mask[7] = 0x07;
}

void		ft_putwchar(wchar_t c)
{
	int		i;
	char	mask[8];

	if (ft_isascii(c))
		ft_putchar(c);
	else if (c <= 0x10FFFF)
	{
		setmask(mask);
		i = bitcount(c);
		ft_putchar(mask[i - 1] | (mask[i + 3] & (c >> (6 * (i - 1)))));
		while (--i)
		{
			ft_putchar(mask[0] | (mask[4] & (c >> (6 * (i - 1)))));
		}
	}
}
