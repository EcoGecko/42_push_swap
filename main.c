/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/27 21:22:40 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int argc, char *argv[])//run prog as ARGS="" ./a.out ${=ARGS}
{
	int i = -1;
	if (argc < 2)
		return (1);
	while(argv[++i])
		ft_printf("%s\n", argv[i]);
	return (0);
}
