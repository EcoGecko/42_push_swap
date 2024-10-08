/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:42 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/12 17:00:42 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_db_free(char **mat)
{
	int	i;

	i = -1;
	if (mat)
	{
		while (mat[++i])
		{
			if (mat[i])
			{
				free(mat[i]);
				mat[i] = NULL;
			}
		}
		free(mat);
		mat = NULL;
	}
}
