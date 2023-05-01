/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/01 11:32:05 by heda-sil         ###   ########.fr       */
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
			if (!ft_strncmp(input[i], input[j], ft_strlen(input[i])))
				return (1);
		j = -1;
		while (input[i][++j])
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
