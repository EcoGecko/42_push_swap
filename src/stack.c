/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:47:31 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 11:59:12 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int capacity, int size)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->capacity = capacity;
	stack->size = size;
	return (stack);
}

void	populate_stack(t_stack *stack, char **input)
{
	t_content	*content;
	int			i;

	i = stack->size;
	while (--i >= 0)
	{
		content = ft_calloc(1, sizeof(t_content));
		content->value = ft_atoi(input[i]);
		content->index = -1;
		ft_lstadd_front(&stack->stack, ft_lstnew((t_content *)content));
	}
}

/*Inserts a node to stack top*/
void	push_stack(t_stack *stack, t_list *node)
{
	if (!node)
		return ;
	if (!stack->stack)
	{
		stack->stack = node;
		stack->stack->next = NULL;
		stack->size++;
		return ;
	}
	node->next = stack->stack;
	stack->stack = node;
	stack->size++;
}

/*Removes the top node from stack*/
t_list	*pop_stack(t_stack *stack)
{
	t_list	*node;

	if (!stack)
		return (NULL);
	if (!stack->stack)
		return (NULL);
	node = stack->stack;
	if (stack->size == 1)
		stack->stack = NULL;
	else
		stack->stack = stack->stack->next;
	stack->size--;
	return (node);
}
