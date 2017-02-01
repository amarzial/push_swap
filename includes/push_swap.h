/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:53:43 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/01 15:49:33 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "mystack.h"
# include "bonus.h"
# include "libft.h"
# define LTOI(x) *(int*)x->content

typedef enum	e_select
{
	A = 0,
	B
}				t_select;

typedef struct	s_algo
{
	size_t		cnt;
	t_stack		*a;
	t_stack		*b;
	size_t		a_size;
	size_t		b_size;
	t_select	sel;
}				t_algo;

int				exec_cmd(char *cmd, t_stack *a, t_stack *b);
int				validarg(const char *arg, t_stack *stack);
void			putarg(const char *arg, t_stack *stack);
void			error_exit(t_stack *stack);
int				perform(char *op, t_stack *a, t_stack *b, t_opts *opt);
void			sort_stack(t_stack *a, t_stack *b, t_opts *opt);
void			upper(t_stack *a, t_stack *b, size_t size, t_opts *opt);
void			lower(t_stack *a, t_stack *b, size_t size, t_opts *opt);

char			*get_op(char *op, t_select selected);

#endif
