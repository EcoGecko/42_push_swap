/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:38:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/13 12:08:57 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
	content = NULL;
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

/*Validates input, checks for duplicates, and for non integer arguments*/
int	validator(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[++i])
	{
		if (!*input[i])
			return (1);
		j = i;
		while (input[++j])
		{
			if (ft_strlen(input[i]) != ft_strlen(input[j]))
				continue ;
			if (!ft_strncmp(input[i], input[j], ft_strlen(input[i])))
				return (1);
		}
		if (check_values(input[i]))
			return (1);
	}
	return (0);
}

int	check_values(char *input)
{
	int	i;

	if (ft_strlen(input) > 11)
		return (1);
	if (ft_atol(input) > INT_MAX || ft_atol(input) < INT_MIN)
		return (1);
	i = -1;
	while (input[++i])
	{
		if (input[i] == '-' && i == 0)
			i++;
		if (!ft_isdigit(input[i]))
			return (1);
	}
	return (0);
}
