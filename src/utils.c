/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:38:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/04 14:45:12 by heda-sil         ###   ########.fr       */
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

/*Validates input, checks for duplicates, and for non integer arguments*/
int	validator(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[++i])
	{
		is_int_range(input[i]);
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

/*Checks if argument is outside of int range*/
void	is_int_range(char *input)
{
	if (ft_strlen(input) >= 10 && input[9] > '7')
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(input) >= 11 && input[0] == '-' && input[10] > '8')
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
