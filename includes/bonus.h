/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:22:17 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 15:31:16 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "bonus.h"
# include "mystack.h"

typedef struct	s_opts
{
	int		verbose:1;
	int		color:1;
	int		flush;
	int		size;
}				t_opts;

void			opt_parse(int argc, const char *argv[], t_opts *opt);
void			print_status(t_stack *a, t_stack *b);
void			print_special(char *op, t_stack *a, t_stack *b, t_opts *opt);

#endif
