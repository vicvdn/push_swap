/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:32:28 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/01 18:18:20 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_node **head_from, t_node **head_to, t_data *data)
{
	t_node	*push_node;

	if (!(*head_from))
		return ;
	push_node = (*head_from);
	(*head_from) = (*head_from)->next;
	if ((*head_from))
		(*head_from)->prev = NULL;
	push_node->prev = NULL;
	if (!(*head_to))
	{
		(*head_to) = push_node;
		*(&data->stack_b->tail) = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = (*head_to);
		push_node->next->prev = push_node;
		(*head_to) = push_node;
	}
	(void)data;
}

void	pa(t_data *data)
{
	push(&data->stack_b->head, &data->stack_a->head, data);
	data->stack_a->len += 1;
	data->stack_b->len -= 1;
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	push(&data->stack_a->head, &data->stack_b->head, data);
	data->stack_a->len -= 1;
	data->stack_b->len += 1;
	ft_printf("pb\n");
}
