/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/05 20:23:28 by heda-sil         ###   ########.fr       */
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
			if (data->b->size == 0)
			{
				while (data->a->size > 3 && data->b->size < 2)
				{
					ft_max(&data->b->max, ((t_info *)data->a->stack->content)->index);
					ft_min(&data->b->min, ((t_info *)data->a->stack->content)->index);
					px(data->a, data->b, "pa");
				}
			}
			while (data->a->size > 3) //get lower cost movement and sort nbrs into stack b
			{
				get_curr_index(data->a);
				get_curr_index(data->b);
				px(data->a, data->b, "pa");
				break ;
			}
			if (data->a->size == 3 && !is_sorted(data->a)) //BUG if stack a is already sorted it will unsorted
				tri_sorter(data->a);
			while (data->b->size > 0) //put nbrs back into stack one
			{
				get_curr_index(data->a);
				get_curr_index(data->b);
				break ;
			}
			break ;
		}
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
		if (((t_info *)tmp->content)->index > ((t_info *)tmp->next->content)->index)
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
