/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:38:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/05/02 11:43:09 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}
void	clean_data(t_data *data)
{
	if (data->a)
		clean_stack(data->a);
	if (data->b)
		clean_stack(data->b);
}

void	clean_stack(t_stack *stack)
{
	ft_lstclear(&stack->stack, del);
	free(stack);
}
