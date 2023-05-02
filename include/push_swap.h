/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:56:34 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 11:42:47 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_content
{
	int	value;
	int	index;
	int	cost;
}			t_content;

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
t_stack	*create_stack(int capacity);
void	populate_stack(t_stack *stack, char **input, int size);
void	push_stack(t_stack *stack, t_list *node);
t_list	*pop_stack(t_stack *stack);

//OPS
void	sx(t_stack *stack, char *op);
void 	ss(t_data *data);
void	px(t_stack *src, t_stack *dst, char *op);

//OPS2
void	rx(t_stack *stack, char *op);
void	rr(t_data *data);
void	rrx(t_stack *stack, char *op);
void	rrr(t_data *data);

//UTILS
void	del(void *content);
void	clean_data(t_data *data);
void	clean_stack(t_stack *stack);
#endif
