/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:43:16 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/12 16:56:17 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Finds curr value position on stack*/
void	get_curr_index(t_stack *stack)
{
	int		i;
	t_list	*tmp;

	tmp = stack->stack;
	i = -1;
	while (tmp)
	{
		((t_info *)tmp->content)->pos = ++i;
		tmp = tmp->next;
	}
}

/*Finds the value final sorted index*/
void	get_final_index(t_stack *stack)
{
	t_list	*curr;
	t_list	*tmp;

	if (!stack || !stack->stack)
		return ;
	curr = stack->stack;
	while (curr)
	{
		tmp = stack->stack;
		((t_info *)curr->content)->index = stack->capacity - 1;
		while (tmp)
		{
			if (((t_info *)curr->content)->value < \
					((t_info *)tmp->content)->value)
				((t_info *)curr->content)->index--;
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

/* Performs stack operations */
void	do_ops(t_data *data) //TODO! NEEDS REFACTOR SPLIT INTO TWO 
{
	t_info	*info_b;
	t_list	*tmp;

	tmp = data->b->stack;
	while (tmp && data->b->cheapest != ((t_info *)tmp->content)->cost)
		tmp = tmp->next;
	info_b = tmp->content;
	if (info_b->ops_idx == 0)
	{
		info_b->r[0] -= info_b->r[2];
		info_b->r[1] -= info_b->r[2];
		while (--info_b->r[2] > -1)
			rr(data);
		while (--info_b->r[0] > -1)
			rx(data->a, "ra");
		while (--info_b->r[1] > -1)
			rx(data->b, "rb");
	}
	if (info_b->ops_idx == 1)
	{
		while (--info_b->r[0] > -1)
			rx(data->a, "ra");
		while (--info_b->rr[1] > -1)
			rrx(data->b, "rrb");
	}
	if (info_b->ops_idx == 2)
	{
		while (--info_b->rr[0] > -1)
			rrx(data->a, "rra");
		while (--info_b->r[1] > -1)
			rx(data->b, "rb");
	}
	if (info_b->ops_idx == 3)
	{
		info_b->rr[0] -= info_b->rr[2];
		info_b->rr[1] -= info_b->rr[2];
		while (--info_b->rr[2] > -1)
			rrr(data);
		while (--info_b->rr[0] > -1)
			rrx(data->a, "rra");
		while (--info_b->rr[1] > -1)
			rrx(data->b, "rrb");
	}
	px(data->b, data->a, "pa");
}
