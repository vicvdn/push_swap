/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:56:25 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/03 15:32:27 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_dlist *stack, t_node **head, t_node **tail, t_data *data)
{
	t_node	*last_node;

	if ((*head) && (*head)->next)
	{
		last_node = find_last_node(head);
		last_node->next = (*head);
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		last_node->next->prev = last_node;
		last_node->next->next = NULL;
		(*tail) = last_node->next;
	}
	(void)stack;
	(void)data;
}

void	ra(t_data *data)
{
	rotate(data->stack_a, &data->stack_a->head, &data->stack_a->tail, data);
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	rotate(data->stack_b, &data->stack_b->head, &data->stack_b->tail, data);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	rotate(data->stack_a, &data->stack_a->head, &data->stack_a->tail, data);
	rotate(data->stack_b, &data->stack_b->head, &data->stack_b->tail, data);
	ft_printf("rr\n");
}
