/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:32:08 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/01 19:06:42 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swaps first two elements of stack x*/
void	sx(t_stack *stack, char *op)
{
	t_list	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->stack;
	stack->stack = stack->stack->next;
	tmp->next = stack->stack->next;
	stack->stack->next = tmp;
	if (op)
		ft_putendl_fd(op, STDIN_FILENO);
}

/*Swaps first two elements of both stacks*/

void	ss(t_data *data)
{
	sx(data->a, NULL);
	sx(data->b, NULL);
	ft_putendl_fd("ss", STDIN_FILENO);
}
