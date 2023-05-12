/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:38:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/12 20:21:29 by heda-sil         ###   ########.fr       */
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
int	validator(char **input) //?DO i need to verify when input is ""
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
		j = -1;
		while (input[i][++j])
		{
			if (input[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(input[i][j]) || \
			(ft_atol(input[i]) > INT_MAX || ft_atol(input[i]) < INT_MIN))
				return (1);
		}
	}
	return (0);
}
