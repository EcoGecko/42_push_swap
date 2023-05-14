/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 16:47:55 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (validator(argv))
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	data.a = create_stack(argc - 1, argc - 1);
	data.b = create_stack(argc - 1, 0);
	populate_stack(data.a, argv + 1);
	get_final_index(data.a);
	sorter(&data);
	clean_data(&data);
	return (EXIT_SUCCESS);
}
