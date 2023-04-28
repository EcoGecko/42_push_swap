/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/28 14:35:04 by heda-sil         ###   ########.fr       */
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
		while (input[++j])
			if (!ft_strncmp(input[i], input[j], ft_strlen(input[i])))
				return (1);
	}
		
	return (0);
}
