/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:04:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/06 12:29:20 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!(*head) || !(*head)->next)
		return ;
	first = (*head);
	second = (*head)->next;
	(*head) = (*head)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
}

void	sa(t_data *data)
{
	swap(&data->stack_a->head);
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	swap(&data->stack_b->head);
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	ft_printf("ss\n");
}
