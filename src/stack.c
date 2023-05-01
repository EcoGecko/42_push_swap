/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:47:31 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/01 12:58:28 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*populate_stack(char **input, int size)
{
	t_stack	*stack;
	t_node	*nbr;
	int		i;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->size = size;
	stack->capacity = size;
	stack->stack = NULL;
	i = size - 1;
	while (i >= 0)
	{
		nbr = ft_calloc(1, sizeof(t_node));
		nbr->value = ft_atoi(input[i]);
		nbr->index = -1;
		ft_lstadd_front(&stack->stack, ft_lstnew((t_node *)nbr));
		i--;
	}
	return (stack);
}
