/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:37:04 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 14:44:19 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Gets all possible operations costs for each element in stack B */
void	get_ops_cost(t_stack *stack_a, t_stack *stack_b)	
{
	t_list	*tmp_b;
	t_info	*info;
	int		limit;

	tmp_b = stack_b->stack;
	stack_b->cheapest = stack_b->capacity;
	while (tmp_b)
	{
		limit = INT_MAX;
		info = ((t_info *)tmp_b->content);
		find_pos(stack_a->stack, info, limit, stack_a->size);
		assign_cost(tmp_b->content, stack_b->size);
		if (stack_b->cheapest > info->cost)
			stack_b->cheapest = info->cost;
		if (stack_b->cheapest == 0)
			break ;
		tmp_b = tmp_b->next;
	}
}

/* Assigns operations costs*/
void	assign_cost(t_info *info, int size)
{
	info->r[1] = info->pos;
	info->r[2] = ft_min(info->r[0], info->r[1]);
	info->rr[1] = size - info->pos;
	info->rr[2] = ft_min(info->rr[0], info->rr[1]);
	info->ops[0] = info->r[0] + info->r[1] - info->r[2];
	info->ops[1] = info->r[0] + info->rr[1];
	info->ops[2] = info->r[1] + info->rr[0];
	info->ops[3] = info->rr[0] + info->rr[1] - info->rr[2];
	info->ops_idx = 0;
	if (info->ops[1] < info->ops[info->ops_idx])
		info->ops_idx = 1;
	if (info->ops[2] < info->ops[info->ops_idx])
		info->ops_idx = 2;
	if (info->ops[3] < info->ops[info->ops_idx])
		info->ops_idx = 3;
	info->cost = info->ops[info->ops_idx];
}

void	find_pos(t_list *lst, t_info *info, int limit, int size)
{
	t_list	*tmp_a;

	tmp_a = lst;
	while (tmp_a)
	{
		if (((t_info *)tmp_a->content)->index > info->index && ((t_info *)tmp_a->content)->index < limit)
		{
			limit = ((t_info *)tmp_a->content)->index;
			info->r[0] = ((t_info *)tmp_a->content)->pos;
			info->rr[0] = size - ((t_info *)tmp_a->content)->pos;

		}
		tmp_a = tmp_a->next;
	}
	if (limit != INT_MAX)
		return ;
	tmp_a = lst;
	while (tmp_a)
	{
		if (((t_info *)tmp_a->content)->index < limit)
		{
			limit = ((t_info *)tmp_a->content)->index;
			info->r[0] = ((t_info *)tmp_a->content)->pos;
			info->rr[0] = size - ((t_info *)tmp_a->content)->pos;
		}
		tmp_a = tmp_a->next;
	}
}
