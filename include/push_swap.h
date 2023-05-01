/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:56:34 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/01 12:01:59 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int	value;
	int	index;
	int	cost;
}			t_node;

typedef struct s_stack
{
	t_list	*stack;
	int		size;
	int 	capacity;
}			t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}			t_data;

//PARSER
int		validator(char **input);

//STACK
t_stack	*populate_stack(char **input, int size);

//OPS
void	sx(t_stack *stack, char *op);
void 	ss(t_data *data);
#endif
