/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:56:34 by heda-sil          #+#    #+#             */
/*   Updated: 2023/04/28 14:25:38 by heda-sil         ###   ########.fr       */
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
}			t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_data;

//PARSER
int	validator(char **input);
#endif
