/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 11:36:41 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validator(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[++i])
	{
		j = i;
		while (input[++j]) //check duplicates
			if (!ft_strncmp(input[i], input[j], ft_strlen(input[i])) && \
					ft_strlen(input[i]) == ft_strlen(input[j]))
				return (1);
		j = -1;
		while (input[i][++j]) //check if all digits
		{
			if (input[i][j] == '-' && !j)
			{
				if (!ft_isdigit(input[i][j + 1]))
					return (1);
			}
			else if (!ft_isdigit(input[i][j]))
				return (1);
		}
	}
	return (0);
}
