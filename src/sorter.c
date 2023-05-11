/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/11 18:04:31 by heda-sil         ###   ########.fr       */
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
		else if (data->b->size == 0 && !is_sorted(data->a))
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
		}
		sort_a(data);
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

void	sort_a(t_data *data)
{
	t_list	*tmp;
	int		rot;
	int		rrot;

	if (data->b->size > 0)
	{
		if (!is_sorted(data->a) && data->a->size == 3)
			tri_sorter(data->a);
//		ft_printf("STACK A\n"); //REMOVE
//		print_stack(data->a); //REMOVE
//		ft_printf("STACK B\n"); //REMOVE
//		print_stack(data->b); //REMOVE
		get_ops_cost(data->a, data->b); //get lower cost movement and sort 	nbrs into stack b
		do_ops(data);
//		ft_printf("AFTER DO_OPS\n"); //REMOVE
//		ft_printf("STACK A\n"); //REMOVE
//		print_stack(data->a); //REMOVE
//		ft_printf("STACK B\n"); //REMOVE
//		print_stack(data->b); //REMOVE
//		exit(0); //REMOVE

	}
	if (data->b->size == 0)
	{
		tmp = data->a->stack;
		get_curr_index(data->a);
		while (tmp && ((t_info *)tmp->content)->index != 0)
			tmp = tmp->next;
//		print_stack(data->a); //REMOVE
		rrot = data->a->size - ((t_info *)tmp->content)->pos;
		rot = ((t_info *)tmp->content)->pos;
//		 exit(0); //REMOVE
		if (rot < rrot)
			while (--rot > -1)
				rx(data->a, "ra");
		else
			while (--rrot > -1)
				rrx(data->a, "rra");
//		print_stack(data->a); //REMOVE
	}
}
