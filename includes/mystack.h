/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:09:46 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/04 02:26:40 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTACK_H
# define MYSTACK_H
# include "libft.h"

typedef struct	s_stack
{
	t_list	*begin;
	t_list	*end;
}				t_stack;

t_stack			*stack_push(t_stack *stack, void *value, size_t size);
t_stack			*stack_push_back(t_stack *stack, void *value, size_t size);
size_t			stack_size(t_stack *stack);
int				stack_is_sorted(t_stack *stack);
int				stack_is_nsorted(t_stack *stack, size_t size);
void			stack_clear(t_stack *stack);
void			*stack_pop(t_stack *stack);
void			stack_move(t_stack *dest, t_stack *src);
void			stack_rotate(t_stack *stack);
void			stack_rev_rotate(t_stack *stack);
void			stack_swap(t_stack *stack);
void			stack_limits(t_stack *stack, int *lims);
int				stack_pivot(t_stack *stack, size_t size);
size_t			min_index(t_stack *s, size_t size);
size_t			max_index(t_stack *s, size_t size);

#endif
