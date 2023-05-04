/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:43:16 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/04 14:55:20 by heda-sil         ###   ########.fr       */
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
		((t_content *)tmp->content)->pos = i;
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
		((t_content *)curr->content)->index = stack->capacity - 1;
		while (tmp)
		{
			if (((t_content *)curr->content)->value < \
					((t_content *)tmp->content)->value)
				((t_content *)curr->content)->index--;
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

int	ft_min(int nbr_1, int nbr_2)
{
	if (nbr_1 < nbr_2)
		return (nbr_1);
	else
		return (nbr_2);
}

int	ft_max(int nbr_1, int nbr_2)
{
	if (nbr_1 > nbr_2)
		return (nbr_1);
	else
		return (nbr_2);
}
