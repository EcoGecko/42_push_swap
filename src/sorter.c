/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/04 15:01:25 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*main sorting function*/
void	sorter(t_data *data)
{
	while (!is_sorted(data->a))
	{
		if (data->a->capacity == 2)
			sx(data->a, "sa");
		else if (data->a->capacity == 3)
			tri_sorter(data->a);
		else
		{
			if (data->b->size == 0)
			{
				while (data->a->size > 3 && data->b->size < 2)
				{
					ft_max(data->b->max, ((t_content *)data->a->stack->content)->index);
					px(data->a, data->b, "pa");
				}
			}
			while (data->a->size > 3)
			{
				get_curr_index(data->a);
				get_curr_index(data->b);
			}
			if (data->a->size == 3)
				tri_sorter(data->a);
			break ;
		}
	}
}

/*Checks if stack is sorted*/
int	is_sorted(t_stack *stack)
{
	int		i;
	t_list	*tmp;

	if (stack->size != stack->capacity)
		return (1);
	tmp = stack->stack;
	i = -1;
	while (++i < stack->capacity)
	{
		if (((t_content *)tmp->content)->index != i)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
