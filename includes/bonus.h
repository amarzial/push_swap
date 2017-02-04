/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:22:17 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 20:11:38 by amarzial         ###   ########.fr       */
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
	int		fd;
	int		flush;
	int		size;
}				t_opts;

void			opt_push_swap(int argc, const char *argv[], t_opts *opt);
void			opt_checker(int argc, const char *argv[], t_opts *opt);
void			print_status(t_stack *a, t_stack *b);
void			print_special(char *op, t_stack *a, t_stack *b, t_opts *opt);

#endif
