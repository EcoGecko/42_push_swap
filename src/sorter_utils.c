/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:43:16 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/05 20:07:30 by heda-sil         ###   ########.fr       */
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

/*returns the minimum value*/
void	ft_min(int *x, int y)
{
	if (*x < y)
		return ;
	else
		*x = y;
}

void	ft_max(int *x, int y)
{
	if (*x > y)
		return ;
	else
		*x = y;
}
