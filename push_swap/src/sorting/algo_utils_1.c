/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:48:32 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:37 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_op_count(t_ops *op_count)
{
	op_count->sa = 0;
	op_count->sb = 0;
	op_count->ss = 0;
	op_count->pa = 0;
	op_count->pb = 0;
	op_count->ra = 0;
	op_count->rb = 0;
	op_count->rr = 0;
	op_count->rra = 0;
	op_count->rrb = 0;
	op_count->rrr = 0;
	op_count->total = 0;
}

void	update_cost(t_node *node, t_node *pivot)
{
	node->op_count->sa = node->op_count->sa + pivot->op_count->sa;
	node->op_count->sb = node->op_count->sb + pivot->op_count->sb;
	node->op_count->pb = node->op_count->pb + 1;
	node->op_count->ra = node->op_count->ra + pivot->op_count->ra;
	node->op_count->rb = node->op_count->rb + pivot->op_count->rb;
	node->op_count->rra = node->op_count->rra + pivot->op_count->rra;
	node->op_count->rrb = node->op_count->rrb + pivot->op_count->rrb;
	if ((node->op_count->ra > 0) && (node->op_count->rb > 0))
		update_rr(node);
	if ((node->op_count->rra > 0) && (node->op_count->rrb > 0))
		update_rrr(node);
	update_total(node);
}

t_node	*get_pivot(t_dlist *stack, int nb)
{
	t_node	*cur_node;

	cur_node = stack->head;
	while (cur_node != NULL)
	{
		if (cur_node->data == nb)
			return (cur_node);
		cur_node = cur_node->next;
	}
	return (NULL);
}

int	get_pos(t_node **head, t_node *node)
{
	int		pos;
	t_node	*cur_node;

	pos = 1;
	cur_node = (*head);
	while (cur_node)
	{
		if (cur_node->data == node->data)
			return (pos);
		cur_node = cur_node->next;
		pos++;
	}
	return (-1);
}

int	get_middle(int len)
{
	if (len % 2 == 0)
		return (len / 2);
	return ((len / 2) + 1);
}
