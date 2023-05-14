/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:32:08 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 16:06:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*Swaps first two elements of stack x*/
void	sx(t_stack *stack)
{
	t_list	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->stack;
	stack->stack = stack->stack->next;
	tmp->next = stack->stack->next;
	stack->stack->next = tmp;
}

/*Swaps first two elements of both stacks*/
void	ss(t_data *data)
{
	sx(data->a);
	sx(data->b);
}

/*Pushes top value from stack y and puts it in stack x*/
void	px(t_stack *src, t_stack *dst)
{
	if (!src->size)
		return ;
	push_stack(dst, pop_stack(src));
}
