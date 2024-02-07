/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:42:41 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/07 11:49:13 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	max_to_top(t_node *max, t_data *data)
{
	make_rotations(max, data);
	make_rev_rotations(max, data);
}

void	min_to_top(t_data *data)
{
	t_node	*min;
	int		pos;

	min = get_pivot(data->stack_a, compute_min(&data->stack_a->head));
	pos = get_pos(&data->stack_a->head, min);
	init_op_count(min->op_count);
	cost_to_head(min, pos, data->stack_a, data);
	make_rotations(min, data);
	make_rev_rotations(min, data);
}

void	find_target(t_dlist *stack_a, t_dlist *stack_b, t_node *node)
{
	t_node	*cur_node;
	long	computed_dist;
	long	distance;

	distance = LONG_MAX;
	cur_node = stack_a->head;
	while (cur_node != NULL)
	{
		if (stack_b->head->data < cur_node->data)
			computed_dist = cur_node->data - stack_b->head->data;
		else
			computed_dist = ft_abs(stack_b->head->data - cur_node->data);
		if (computed_dist < distance && cur_node->data > node->data)
		{
			distance = computed_dist;
			stack_b->head->dist->data = cur_node->data;
		}
		cur_node = cur_node->next;
	}
	if (distance == LONG_MAX)
		stack_b->head->dist->data = compute_min(&stack_a->head);
}

// void	max_in_a(t_data *data, t_node **tail)
// {
// 	rra(data);
// 	print_node((*tail)->prev);
// 	if ((*tail)->prev->data > (*tail)->pivot->data)
// 	{
// 		rra(data);
// 		find_target(data);
// 		if ((*tail)->prev->data > (*tail)->pivot->data)
// 			rra(data);
// 	}
// }

// void	max_in_b(t_data *data)
// {
// 	int		i;

// 	i = 3;
// 	// find_target(data);
// 	(*(&data->stack_a->tail))->pivot =
// 		get_pivot(data, (*(&data->stack_a->tail))->dist->data);
// 	while (i > 0 && data->stack_b->head)
// 	{
// 		while ((*(&data->stack_a->tail))->pivot != *(&data->stack_b->head))
// 			pa(data);
// 		rra(data);
// 		// pa(data);
// 		// pa(data);
// 		i--;
// 		find_target(data);
// 	}
// 	while (*(&data->stack_b->head))
// 		pa(data);
// }

// void	push_back(t_node **head, t_data *data)
// {
// 	t_node	*max;
// 	t_dlist	*stack;
// 	int		pos;

// 	max = get_pivot(data, get_max(head));
// 	pos = get_pos(head, max);
// 	init_op_count(max->op_count);
// 	cost_to_head(max, pos, data->stack_b, data);
// 	stack = data->stack_b;
// 	max_to_top(max, data);
// 	find_targets(stack_a);
// 	if (max->data < get_max(&data->stack_a->head))
// 		max_in_a(data, &data->stack_b->tail);
// 	else if (max->data > get_max(&data->stack_a->head))
// 		max_in_b(data);
// 	// if (!(*(&data->stack_b->head)) && is_sorted(&data->stack_a->head))
// 	// 	rra(data);
// 	// else
// 	// {
// 	// 	max_in_a(data);
// 	// }
// }

void	target_to_top(t_node *node, t_data *data)
{
	int	pos;

	pos = get_pos(&data->stack_a->head, node);
	if (pos == 1)
		return ;
	init_op_count(node->op_count);
	cost_to_head(node, pos, data->stack_a, data);
	make_rotations(node, data);
	make_rev_rotations(node, data);
}

void	push_back(t_node **head, t_data *data)
{
	t_node	*max;
	t_node	**head_a;
	int		pos;
	int		i;

	head_a = (&data->stack_a->head);
	max = get_pivot(data->stack_b, get_max(head));
	pos = get_pos(head, max);
	init_op_count(max->op_count);
	cost_to_head(max, pos, data->stack_b, data);
	max_to_top(max, data);
	i = data->stack_b->len;
	while (i > 0)
	{
		find_target(data->stack_a, data->stack_b, (*head));
		(*head)->pivot = get_pivot(data->stack_a, (*head)->dist->data);
		target_to_top((*head)->pivot, data);
		pa(data);
		i--;
	}
	if (get_pos(head_a, get_pivot(data->stack_a, compute_min(head_a))) != 1)
		min_to_top(data);
}
