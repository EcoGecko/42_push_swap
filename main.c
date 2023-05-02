/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 12:13:42 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack) //REMOVE tmp function to print stacks
{
	t_list		*tmp;

	if (stack)
	{
		tmp = stack->stack;
		while (tmp)
		{
			ft_printf("[%d]\n", ((t_content *)tmp->content)->value);
			tmp = tmp->next;
		}
	}
}	

/* void	print_stack(t_list **stack) //REMOVE tmp function to print stacks */
/* { */
/* 	t_list		*tmp; */

/* 	if (stack) */
/* 	{ */
/* 		tmp = *stack; */
/* 		while (tmp) */
/* 		{ */
/* 			ft_printf("[%d]\n", ((t_content *)tmp->content)->value); */
/* 			tmp = tmp->next; */
/* 		} */
/* 	} */
/* } */	

int	main(int argc, char *argv[])//run prog as ARGS="" ./a.out ${=ARGS}
{
	t_data	data;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (validator(argv))
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	data.a = create_stack(argc - 1, argc -1);
	data.b = create_stack(argc - 1, 0);
	populate_stack(data.a, argv + 1);
	ft_printf("-----STACK A-----\n"); //REMOVE just printing stacks to visualize better
	print_stack(data.a); //prints stack
	ft_printf("-----STACK A-----\n");
	print_stack(data.a); //prints stack
	ft_printf("-----STACK B-----\n");
	print_stack(data.b); //prints stack
	clean_data(&data);
	return (EXIT_SUCCESS);
}
