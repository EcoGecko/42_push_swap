/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:32:08 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/08 17:54:13 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swaps first two elements of stack x*/
void	sx(t_stack *stack, char *op)
{
	t_list	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->stack;
	stack->stack = stack->stack->next;
	tmp->next = stack->stack->next;
	stack->stack->next = tmp;
	if (op)
		ft_putendl_fd(op, STDOUT_FILENO);
}

/*Swaps first two elements of both stacks*/
void	ss(t_data *data)
{
	sx(data->a, NULL);
	sx(data->b, NULL);
	ft_putendl_fd("ss", STDOUT_FILENO);
}

/*Pushes top value from stack y and puts it in stack x*/
void	px(t_stack *src, t_stack *dst, char *op)
{
	if (!src->size)
		return ;
	push_stack(dst, pop_stack(src));
	ft_putendl_fd(op, STDOUT_FILENO);
}

/* Gets all possible operations costs for each element in stack B */
void	get_ops_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	get_curr_index(stack_b);
	tmp_b = stack_b->stack;
	while (tmp_b)
	{
		tmp_a = stack_a->stack;
		((t_info *)tmp_b->content)->rr[0] = stack_a->size;
		while (((t_info *)tmp_b->content)->index > \
		((t_info *)tmp_a->content)->index)
		{
			((t_info *)tmp_b->content)->r[0]++;
			((t_info *)tmp_b->content)->rr[0]--;
			tmp_a = tmp_a->next;
		}
		assign_cost(tmp_b->content, stack_b->size);
		tmp_b = tmp_b->next;
	}
}

/* Assigns operations costs*/
void	assign_cost(t_info *info, int size)
{
		info->r[1] = info->pos;
		info->rr[1] = size - info->pos;
		info->r[2] = ft_min(info->r[0], info->r[1]);
		info->rr[2] = ft_min(info->rr[0], info->rr[1]);
		info->ops[0] = info->r[0] + info->r[1] - info->r[2];
		info->ops[1] = info->r[0] + info->rr[1];
		info->ops[2] = info->rr[0] + info->r[1];
		info->ops[3] = info->rr[0] + info->rr[1] - info->rr[2];
		info->ops_idx = 0;
		if (info->ops[1] < info->ops[info->ops_idx])
			info->ops_idx = 1;
		else if (info->ops[2] < info->ops[info->ops_idx])
			info->ops_idx = 2;
		else if (info->ops[3] < info->ops[info->ops_idx])
			info->ops_idx = 3;
		info->cost = info->ops[info->ops_idx];
		ft_printf("pos0[%d]\n", info->ops[0]);
		ft_printf("pos1[%d]\n", info->ops[1]);
		ft_printf("pos2[%d]\n", info->ops[2]);
		ft_printf("pos3[%d]\n", info->ops[3]);
		ft_printf("OPS_ID[%d]\n", info->ops_idx);
		ft_printf("COST[%d]\n", info->cost);
}