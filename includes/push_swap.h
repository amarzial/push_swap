/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:53:43 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/20 20:59:13 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "mystack.h"
# include "libft.h"

int		exec_cmd(char *cmd, t_stack *a, t_stack *b);
int		validarg(const char *arg, t_stack *stack);
void	error_exit(t_stack *stack);

#endif
