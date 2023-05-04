/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:56:34 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/04 15:00:58 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_info
{
	int	value;
	int	index; //final index
	int	pos; //curr position in stack
	int	r[3]; //nbr of ra rb and rr
	int	rr[3]; //nbr of rra rrb and rrr
	int	cost; //total nbr of moves
}			t_info;

typedef struct s_stack
{
	t_list	*stack;
	int		size;
	int		capacity;
	int		max;
}			t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}			t_data;

//REMOVE
void	print_stack(t_stack *stack);

//SORTER
void	sorter(t_data *data);
int		is_sorted(t_stack *stack);
void	tri_sorter(t_stack *stack);

//SORTER_UTILS
void	get_curr_index(t_stack *stack);
void	get_final_index(t_stack *stack);
int		ft_min(int x, int y);
int		ft_max(int x, int y);

//STACK
t_stack	*create_stack(int capacity, int size);
void	populate_stack(t_stack *stack, char **input);
void	push_stack(t_stack *stack, t_list *node);
t_list	*pop_stack(t_stack *stack);

//OPS
void	sx(t_stack *stack, char *op);
void	ss(t_data *data);
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
int		validator(char **input);
void	is_int_range(char *input);
#endif
