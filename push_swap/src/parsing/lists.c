/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:09:15 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/05 11:06:19 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free_stack(t_node **head, t_node **tail)
{
	t_node	*cur_node;
	t_node	*temp;

	if (!*head)
		return ;
	cur_node = (*head);
	while (cur_node != (*tail))
	{
		temp = cur_node->next;
		free_node(cur_node);
		cur_node = temp;
	}
	if (*tail)
		free_node((*tail));
}

t_node	*create_node(int nb, t_data *data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (ft_free_stack(&data->stack_a->head, &data->stack_a->tail),
			free(data->stack_a), ft_printf("Allocation issue."), NULL);
	new_node->data = nb;
	new_node->op_count = malloc(sizeof(t_ops));
	new_node->dist = malloc(sizeof(t_dist));
	if (!new_node->op_count || !new_node->dist)
		return (ft_error(2), NULL);
	init_op_count(new_node->op_count);
	new_node->dist->data = 0;
	new_node->dist->distance = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*find_last_node(t_node **head)
{
	t_node	*cur_node;

	cur_node = (*head);
	while (cur_node->next != NULL)
		cur_node = cur_node->next;
	return (cur_node);
}

void	insert_end(t_node **head, t_node **tail, int nb, t_data *data)
{
	t_node	*new_node;

	new_node = create_node(nb, data);
	if (*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
		data->stack_a->len = 1;
	}
	else
	{
		(*tail) = find_last_node(head);
		if (data->stack_a->len == 1)
			(*head)->next = new_node;
		(*tail)->next = new_node;
		new_node->prev = (*tail);
		(*tail) = new_node;
		(*tail)->next = NULL;
		data->stack_a->len += 1;
	}
}

void	create_stacks(t_data *data)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = malloc(sizeof * stack_a);
	stack_b = malloc(sizeof * stack_b);
	if (!stack_a || !stack_b)
		return ;
	if (stack_a)
	{
		stack_a->len = 0;
		stack_a->head = NULL;
		stack_a->tail = NULL;
	}
	if (stack_b)
	{
		stack_b->len = 0;
		stack_b->head = NULL;
		stack_b->tail = NULL;
	}
	data->stack_a = stack_a;
	data->stack_b = stack_b;
}
