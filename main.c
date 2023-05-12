/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/12 15:43:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack) // REMOVE tmp function to print stacks
{
	t_list	*tmp;

	if (stack)
	{
		tmp = stack->stack;
		ft_printf("[VALUE]-[INDEX]-[POS]-[MAX]\n");
		while (tmp)
		{
			ft_printf("[%d]-[%d]-[%d]-[%d]\n", \
			((t_info *)tmp->content)->value, ((t_info *)tmp->content)->index, \
			((t_info *)tmp->content)->pos, stack->max);
			tmp = tmp->next;
		}
	}
}

int	main(int argc, char *argv[]) // run prog as ARGS="" ./a.out ${=ARGS}
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
