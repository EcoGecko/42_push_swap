/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:38:10 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 16:07:05 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*Shift up all elements of stack x by 1, first becomes last*/
void	rx(t_stack *stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || stack->size < 2)
		return ;
	last = ft_lstlast(stack->stack);
	tmp = stack->stack;
	stack->stack = stack->stack->next;
	tmp->next = NULL;
	last->next = tmp;
}

/*Shift up all elements of both stacks by 1, first becomes last*/
void	rr(t_data *data)
{
	rx(data->a);
	rx(data->b);
}

/*Shift down all elements of stack x by 1, last becomes first*/
void	rrx(t_stack *stack)
{
	t_list	*tmp;
	t_list	*last;
	int		i;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->stack;
	last = ft_lstlast(stack->stack);
	i = -1;
	while (++i < stack->size - 2)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = stack->stack;
	stack->stack = last;
}

/*Shift down all elements of stack x by 1, last becomes first*/
void	rrr(t_data *data)
{
	rrx(data->a);
	rrx(data->b);
}
