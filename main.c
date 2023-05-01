/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/01 17:51:47 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

void	print_stack(t_stack *stack) //REMOVE tmp function to print stacks
{
	t_list *tmp;
	t_node	*node;

	if (stack)
	{
		tmp = stack->stack;
		while (tmp)
		{
			node = tmp->content;
			ft_printf("[%d]\n", node->value);
			tmp = tmp->next;
		}
	}
}	

int	main(int argc, char *argv[])//run prog as ARGS="" ./a.out ${=ARGS}
{
	t_data	data;

	if (argc < 2)
		return (1);
	if (validator(argv))
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		return (1);
	}
	data.a = populate_stack(argv + 1, argc - 1);
	data.b = NULL;
	ft_printf("-----STACK A-----\n"); //REMOVE just printing stacks to visualize better
	print_stack(data.a); //prints stack
	ft_printf("-----STACK A-----\n");
	print_stack(data.a); //prints stack
	ft_printf("-----STACK B-----\n");
	print_stack(data.b); //prints stack
	ft_lstclear(&data.a->stack, del); //clears list and frees all content mem
	free(data.a);
	return (0);
}
