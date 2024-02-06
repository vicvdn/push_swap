/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:14:54 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/03 15:32:12 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate(t_dlist *stack, t_node **head, t_node **tail, t_data *data)
{
	t_node	*last_node;

	if ((*head) && (*head)->next)
	{
		last_node = find_last_node(head);
		last_node->prev->next = NULL;
		last_node->next = (*head);
		last_node->prev = NULL;
		(*head) = last_node;
		last_node->next->prev = last_node;
	}
	(*tail) = find_last_node(head);
	(void)stack;
	(void)data;
	(void)tail;
}

void	rra(t_data *data)
{
	rev_rotate(data->stack_a, &data->stack_a->head, &data->stack_a->tail, data);
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	rev_rotate(data->stack_b, &data->stack_b->head, &data->stack_b->tail, data);
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	rev_rotate(data->stack_a, &data->stack_a->head, &data->stack_a->tail, data);
	rev_rotate(data->stack_b, &data->stack_b->head, &data->stack_b->tail, data);
	ft_printf("rrr\n");
}
