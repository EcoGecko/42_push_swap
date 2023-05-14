/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:24:02 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 16:55:57 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"

typedef struct s_info
{
	int	value;
	int	index;
	int	pos;
	int	r[3];
	int	rr[3];
	int	ops[4];
	int	ops_idx;
	int	cost;
}			t_info;

typedef struct s_stack
{
	t_list	*stack;
	int		size;
	int		capacity;
	int		max;
	int		cheapest;
}			t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}			t_data;

int		read_input(t_data *data);
int		do_op(t_data *data, char *op);
void	get_final_index(t_stack *stack);

//STACK
t_stack	*create_stack(int capacity, int size);
void	populate_stack(t_stack *stack, char **input);
void	push_stack(t_stack *stack, t_list *node);
t_list	*pop_stack(t_stack *stack);
void	clean_stack(t_stack *stack);

//OPS
void	sx(t_stack *stack);
void	ss(t_data *data);
void	px(t_stack *src, t_stack *dst);

//OPS2
void	rx(t_stack *stack);
void	rr(t_data *data);
void	rrx(t_stack *stack);
void	rrr(t_data *data);

//UTILS
void	del(void *content);
void	clean_data(t_data *data);
int		validator(char **input);
int		check_values(char *input);
int		is_sorted(t_stack *stack);

#endif