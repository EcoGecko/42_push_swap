/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:56:34 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/14 16:55:48 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

//SORTER
void	sorter(t_data *data);
int		is_sorted(t_stack *stack);
void	tri_sorter(t_stack *stack);
void	sort_a(t_data *data);
void	sort(t_data *data);

//SORTER_UTILS
void	get_curr_index(t_stack *stack);
void	get_final_index(t_stack *stack);
int		ft_min(int x, int y);
void	do_ops(t_data *data, t_info *info_b);
void	continue_ops(int idx, int rot[2], int rrot[2], t_data *data);

//COSTS
void	get_ops_cost(t_stack *stack_a, t_stack *stack_b);
void	assign_cost(t_info *info, int size);
void	find_pos(t_stack *stack, t_info *info, int limit, int size);
void	set_rot_a(t_info *info, int pos, int size);

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
int		check_values(char *input);

#endif
