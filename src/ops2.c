/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:38:10 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 13:52:48 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*Shift up all elements of stack x by 1, first becomes last*/
void	rx(t_stack *stack, char *op)
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
	if (op)
		ft_putendl_fd(op, STDIN_FILENO);
}

/*Shift up all elements of both stacks by 1, first becomes last*/
void	rr(t_data *data)
{
	rx(data->a, NULL);
	rx(data->b, NULL);
	ft_putendl_fd("rr", STDIN_FILENO);
}

/*Shift down all elements of stack x by 1, last becomes first*/
void	rrx(t_stack *stack, char *op)
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
	if (op)
		ft_putendl_fd(op, STDIN_FILENO);
}

/*Shift down all elements of stack x by 1, last becomes first*/
void	rrr(t_data *data)
{
	rrx(data->a, NULL);
	rrx(data->b, NULL);
	ft_putendl_fd("rrr", STDIN_FILENO);
}
