/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:42:01 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/03 15:08:24 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_min(int node_data, t_node **head)
{
	int		min;

	min = compute_min(head);
	if (node_data < min)
		return (1);
	return (0);
}

int	ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

void	make_rotations(t_node *cheapest_node, t_data *data)
{
	while (cheapest_node->op_count->ra > 0)
	{
		ra(data);
		cheapest_node->op_count->ra -= 1;
	}
	while (cheapest_node->op_count->rb > 0)
	{
		rb(data);
		cheapest_node->op_count->rb -= 1;
	}
	while (cheapest_node->op_count->rr > 0)
	{
		rr(data);
		cheapest_node->op_count->rr -= 1;
	}
}

void	make_rev_rotations(t_node *cheapest_node, t_data *data)
{
	while (cheapest_node->op_count->rra > 0)
	{
		rra(data);
		cheapest_node->op_count->rra -= 1;
	}
	while (cheapest_node->op_count->rrb > 0)
	{
		rrb(data);
		cheapest_node->op_count->rrb -= 1;
	}
	while (cheapest_node->op_count->rrr > 0)
	{
		rrr(data);
		cheapest_node->op_count->rrr -= 1;
	}
}

void	make_push(t_node *cheapest_node, t_data *data)
{
	while (cheapest_node->op_count->pb > 0)
	{
		pb(data);
		cheapest_node->op_count->pb -= 1;
	}
	while (cheapest_node->op_count->pa > 0)
	{
		pa(data);
		cheapest_node->op_count->pa -= 1;
	}
}
