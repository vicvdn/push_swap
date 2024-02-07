/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:31:41 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/07 11:52:48 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	compute_distance(t_node *node, t_data *data)
{
	long	computed_dist;
	long	distance;
	t_node	*cur_node;

	if (is_min(node->data, &data->stack_b->head) == 1)
	{
		node->dist->data = get_max(&data->stack_b->head);
		return ;
	}
	distance = LONG_MAX;
	cur_node = *(&data->stack_b->head);
	while (cur_node != NULL)
	{
		computed_dist = node->data - cur_node->data;
		if (computed_dist < distance && computed_dist > 0)
		{
			distance = computed_dist;
			node->dist->data = cur_node->data;
		}
		cur_node = cur_node->next;
	}
}

void	cost_to_head(t_node *node, int pos, t_dlist *stack, t_data *data)
{
	if (pos == 1)
		return (init_op_count(node->op_count));
	if (node == find_last_node(&stack->head))
	{
		if (stack == data->stack_a)
			node->op_count->rra += 1;
		else
			node->op_count->rrb += 1;
	}
	else if (pos <= get_middle(stack->len))
	{
		if (stack == data->stack_a)
			node->op_count->ra = pos - 1;
		else
			node->op_count->rb = pos - 1;
	}
	else if (pos > get_middle(stack->len))
	{
		if (stack == data->stack_a)
			node->op_count->rra = (stack->len - pos) + 1;
		else
			node->op_count->rrb = (stack->len - pos) + 1;
	}
}

void	compute_cost(t_node *node, t_data *data)
{
	int		pos;

	init_op_count(node->op_count);
	pos = get_pos(&data->stack_a->head, node);
	cost_to_head(node, pos, data->stack_a, data);
	node->pivot = get_pivot(data->stack_b, node->dist->data);
	init_op_count(node->pivot->op_count);
	pos = get_pos(&data->stack_b->head, node->pivot);
	cost_to_head(node->pivot, pos, data->stack_b, data);
	update_cost(node, node->pivot);
}

void	push_cheapest(t_node **head, t_data *data)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest_cost(head);
	make_rotations(cheapest_node, data);
	make_rev_rotations(cheapest_node, data);
	if (*(&data->stack_b->head) == cheapest_node->pivot)
		make_push(cheapest_node, data);
}

void	ft_sorting_algo(t_data *data)
{
	t_node	*cur_node;

	if (data->stack_a->len == 4)
		pb(data);
	else if (data->stack_a->len > 4)
	{
		pb(data);
		pb(data);
	}
	while (data->stack_a->len > 3)
	{
		cur_node = *(&data->stack_a->head);
		while (cur_node != NULL)
		{
			compute_distance(cur_node, data);
			compute_cost(cur_node, data);
			cur_node = cur_node->next;
		}
		push_cheapest(&data->stack_a->head, data);
	}
	mini_sort(data->stack_a, &data->stack_a->head, data);
	push_back(&data->stack_b->head, data);
}
