/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 14:17:24 by heda-sil         ###   ########.fr       */
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
		else if (data->b->size == 0 && !is_sorted(data->a))
		{
			while (data->a->capacity > 6 && data->b->size < \
			data->a->capacity / 2)
			{
				if (((t_info *)data->a->stack->content)->index + 1 <= \
				data->a->capacity / 2)
					px(data->a, data->b, "pb");
				else
					rx(data->a, "ra");
			}
			while (data->a->size > 3)
				px(data->a, data->b, "pb");
		}
		sort(data);
	}
}

/*Checks if stack is sorted*/
int	is_sorted(t_stack *stack)
{
	int		i;
	t_list	*tmp;

	tmp = stack->stack;
	i = -1;
	while (++i < stack->size - 1)
	{
		if (((t_info *)tmp->content)->index > \
		((t_info *)tmp->next->content)->index)
			return (0);
		tmp = tmp->next;
	}
	if (stack->size > 3 && stack->size != stack->capacity)
		return (0);
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
/* Sorts elements from stack B to A */
void	sort(t_data *data)
{
	t_info	*info_b;
	t_list	*tmp;

	if (data->b->size > 0)
	{
		if (!is_sorted(data->a) && data->a->size == 3)
			tri_sorter(data->a);
		get_curr_index(data->a);
		get_curr_index(data->b);
		get_ops_cost(data->a, data->b);
		tmp = data->b->stack;
		while (tmp && data->b->cheapest != ((t_info *)tmp->content)->cost)
			tmp = tmp->next;
		info_b = tmp->content;
		do_ops(data, info_b);
	}
 	if (data->b->size == 0)
		sort_a(data);
}

/* Sorts stack A after stack A becames sortable */
void	sort_a(t_data *data)
{
	int		rot;
	int		rrot;
	t_list	*tmp;

	tmp = data->a->stack;
	get_curr_index(data->a);
	while (tmp && ((t_info *)tmp->content)->index != 0)
		tmp = tmp->next;
	rrot = data->a->size - ((t_info *)tmp->content)->pos;
	rot = ((t_info *)tmp->content)->pos;
	if (rot < rrot)
		while (--rot > -1)
			rx(data->a, "ra");
	else
		while (--rrot > -1)
			rrx(data->a, "rra");
}
