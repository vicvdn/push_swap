/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:11:59 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/03 15:38:13 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_rr(t_node *node)
{
	if (node->op_count->ra < node->op_count->rb)
	{
		node->op_count->rr = node->op_count->ra;
		node->op_count->rb = node->op_count->rb - node->op_count->rr;
		node->op_count->ra = 0;
	}
	else
	{
		node->op_count->rr = node->op_count->rb;
		node->op_count->ra = node->op_count->ra - node->op_count->rr;
		node->op_count->rb = 0;
	}
}

void	update_rrr(t_node *node)
{
	if (node->op_count->rra < node->op_count->rrb)
	{
		node->op_count->rrr = node->op_count->rra;
		node->op_count->rrb = node->op_count->rrb - node->op_count->rrr;
		node->op_count->rra = 0;
	}
	else
	{
		node->op_count->rrr = node->op_count->rrb;
		node->op_count->rra = node->op_count->rra - node->op_count->rrr;
		node->op_count->rrb = 0;
	}
}

void	update_ss(t_node *node)
{
	node->op_count->ss = ft_min(node->op_count->sa, node->op_count->sb);
	if (node->op_count->sa < node->op_count->sb)
		node->op_count->sb = node->op_count->ss - node->op_count->sa;
	else
		node->op_count->sa = node->op_count->ss - node->op_count->sb;
}

void	update_total(t_node *node)
{
	node->op_count->total = node->op_count->sa + node->op_count->sb
		+ node->op_count->ss + node->op_count->pa + node->op_count->pa
		+ node->op_count->ra + node->op_count->rb + node->op_count->rr
		+ node->op_count->rra + node->op_count->rrb + node->op_count->rrr;
}

t_node	*find_cheapest_cost(t_node **head)
{
	t_node	*cur_node;
	int		cost;

	cur_node = (*head);
	cost = INT_MAX;
	while (cur_node != NULL)
	{
		if (cur_node->op_count->total < cost)
			cost = cur_node->op_count->total;
		cur_node = cur_node->next;
	}
	cur_node = (*head);
	while (cur_node != NULL)
	{
		if (cur_node->op_count->total == cost)
			return (cur_node);
		cur_node = cur_node->next;
	}
	return (NULL);
}
