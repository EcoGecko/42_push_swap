/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/01 13:02:04 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int		i;
	t_list	*tmp;
	t_node	*node;

	tmp = stack->stack;
	i = -1;
	while (++i < stack->size)
	{
		ft_printf("%d\n", node->value);
		tmp = tmp->next;
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
	data.stack_a = populate_stack(argv + 1, argc - 1);
	data.stack_b = NULL;
	print_stack(data.stack_a);
	return (0);
}
