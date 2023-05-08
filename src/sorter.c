/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/08 18:15:44 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*main sorting function*/
void	sorter(t_data *data)
{
	while (!is_sorted(data->a)) // maybe add size != capacity | Breaks are tmps just to prevent infinite loops while i get the logic right
	{
		if (data->a->capacity == 2)
			sx(data->a, "sa");
		else if (data->a->capacity == 3)
			tri_sorter(data->a);
		else
		{
			while (data->a->size > 3) 
			{
				if (((t_info *)data->a->stack->content)->index != data->a->max \
				&& ((t_info *)data->a->stack->content)->index != 0 && \
				((t_info *)data->a->stack->content)->index != data->a->max / 2)
					px(data->a, data->b, "pa");
				else
					rx(data->a, "ra");
			}
			if (!is_sorted(data->a))
				tri_sorter(data->a);
			get_ops_cost(data->a, data->b); //get lower cost movement and sort nbrs into stack b
			do_ops(data);
		}
		break ; //DELETE - temporary way to break cycle while i dont finish the sorting
	}
}

/*Checks if stack is sorted*/
int	is_sorted(t_stack *stack)
{
	int		i;
	t_list	*tmp;

	// if (stack->size != stack->capacity)
	// 	return (0);
	tmp = stack->stack;
	i = -1;
	while (++i < stack->size - 1)
	{
		if (((t_info *)tmp->content)->index > \
		((t_info *)tmp->next->content)->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*Sorts 3 elements stack*/
void	tri_sorter(t_stack *stack)
{
	t_info	*first;
	t_info	*second;
	t_info	*third;

	first = (t_info *)stack->stack->content;
	second = (t_info *)stack->stack->next->content;
	third = (t_info *)stack->stack->next->next->content;
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
