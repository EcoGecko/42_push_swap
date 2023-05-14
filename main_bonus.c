/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:54:47 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 19:41:50 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (validator(argv))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	data.a = create_stack(argc - 1, argc - 1);
	data.b = create_stack(argc - 1, 0);
	populate_stack(data.a, argv + 1);
	get_final_index(data.a);
	if (read_input(&data))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		clean_data(&data);
		return (EXIT_FAILURE);
	}
	if (is_sorted(data.a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	clean_data(&data);
	return (EXIT_SUCCESS);
}

int	read_input(t_data *data)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (do_op(data, op))
		{
			free(op);
			return (1);
		}
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	return (0);
}

int	do_op(t_data *data, char *op)
{
	if (!ft_strncmp("sa", op, ft_strlen("sa")) && ft_strlen(op) == 3)
		sx(data->a);
	else if (!ft_strncmp("sb", op, ft_strlen("sb")) && ft_strlen(op) == 3)
		sx(data->b);
	else if (!ft_strncmp("ss", op, ft_strlen("ss")) && ft_strlen(op) == 3)
		ss(data);
	else if (!ft_strncmp("pa", op, ft_strlen("pa")) && ft_strlen(op) == 3)
		px(data->b, data->a);
	else if (!ft_strncmp("pb", op, ft_strlen("pb")) && ft_strlen(op) == 3)
		px(data->a, data->b);
	else if (!ft_strncmp("ra", op, ft_strlen("ra")) && ft_strlen(op) == 3)
		rx(data->a);
	else if (!ft_strncmp("rb", op, ft_strlen("rb")) && ft_strlen(op) == 3)
		rx(data->b);
	else if (!ft_strncmp("rr", op, ft_strlen("rr")) && ft_strlen(op) == 3)
		rr(data);
	else if (!ft_strncmp("rra", op, ft_strlen("rra")) && ft_strlen(op) == 4)
		rrx(data->a);
	else if (!ft_strncmp("rrb", op, ft_strlen("rrb")) && ft_strlen(op) == 4)
		rrx(data->b);
	else if (!ft_strncmp("rrr", op, ft_strlen("rrr")) && ft_strlen(op) == 4)
		rrr(data);
	else
		return (1);
	return (0);
}

/*Finds the value final sorted index*/
void	get_final_index(t_stack *stack)
{
	t_list	*curr;
	t_list	*tmp;

	if (!stack || !stack->stack)
		return ;
	curr = stack->stack;
	while (curr)
	{
		tmp = stack->stack;
		((t_info *)curr->content)->index = stack->capacity - 1;
		while (tmp)
		{
			if (((t_info *)curr->content)->value < \
					((t_info *)tmp->content)->value)
				((t_info *)curr->content)->index--;
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}
