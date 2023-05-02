/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:38:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 13:54:27 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

void	clean_data(t_data *data)
{
	if (data->a)
		clean_stack(data->a);
	if (data->b)
		clean_stack(data->b);
}

void	clean_stack(t_stack *stack)
{
	ft_lstclear(&stack->stack, del);
	free(stack);
}

int	validator(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[++i])
	{
		j = i;
		while (input[++j])
		{
			if (ft_strlen(input[i]) != ft_strlen(input[j]))
				continue ;
			if (!ft_strncmp(input[i], input[j], ft_strlen(input[i])))
				return (1);
		}
		j = -1;
		while (input[i][++j])
		{
			if (input[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(input[i][j]))
				return (1);
		}
	}
	return (0);
}

void	get_index(t_stack *stack)
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
