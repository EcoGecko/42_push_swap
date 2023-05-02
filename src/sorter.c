/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 15:43:18 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_data *data)
{
	while (!is_sorted(data->a))
	{
		if (data->a->size == 2)
			sx(data->a, "sa");
		else if (data->a->size <= 3)
			tri_sorter(data->a);
	}
}

/*Checks if stack is sorted*/
bool	is_sorted(t_stack *stack)
{
	int		i;
	t_list	*tmp;

	if (stack->size != stack ->capacity)
		return (false);
	tmp = stack->stack;
	i = -1;
	while (++i < stack->capacity)
	{
		if (((t_content *)tmp->content)->index != i)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

/*Sorts 3 elements stack*/
void	tri_sorter(t_stack *stack)
{
	t_content	*first;
	t_content	*second;
	t_content	*third;

	first = (t_content *)stack->stack->content;
	second = (t_content *)stack->stack->next->content;
	third = (t_content *)stack->stack->next->next->content;
	if (first->index < second->index && third->index > first->index)
	{
		sx(stack, "sa");
		rx(stack, "ra");
	}
	if (first->index < second->index && third->index < first->index)
		rrx(stack, "rra");
	if (first->index > second->index && second->index > third->index)
	{
		rx(stack, "ra");
		sx(stack, "sa");
	}
	if (second->index < third->index && third->index > first->index)
		sx(stack, "sa");
	if (second->index < third->index && third->index < first->index)
		rx(stack, "ra");
}
