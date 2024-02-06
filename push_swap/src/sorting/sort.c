/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:46:26 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/06 12:24:11 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_node **head)
{
	t_node	*cur_node;

	if (!(*head) || !(*head)->next)
		return (1);
	cur_node = (*head);
	while (cur_node->next != NULL)
	{
		if (cur_node->data < cur_node->next->data)
			cur_node = cur_node->next;
		else
			return (1);
	}
	return (0);
}

int	find_min(t_node **head)
{
	int		i;
	int		min;
	t_node	*cur_node;

	i = 1;
	min = INT_MAX;
	cur_node = (*head);
	while (cur_node != NULL)
	{
		if (cur_node->data < min)
			min = cur_node->data;
		cur_node = cur_node->next;
	}
	cur_node = (*head);
	while (cur_node->data != min)
	{
		i++;
		cur_node = cur_node->next;
	}
	return (i);
}

int	find_max(t_node **head)
{
	int		i;
	int		max;
	t_node	*cur_node;

	i = 1;
	max = INT_MIN;
	cur_node = (*head);
	while (cur_node != NULL)
	{
		if (cur_node->data > max)
			max = cur_node->data;
		cur_node = cur_node->next;
	}
	cur_node = (*head);
	while (cur_node->data != max)
	{
		i++;
		cur_node = cur_node->next;
	}
	return (i);
}

void	mini_sort(t_dlist *stack, t_node **head, t_data *data)
{
	t_node	*middle;

	middle = (*head)->next;
	if (is_sorted(&stack->head) == 0)
		return ;
	if ((find_max(head) == 1) && (find_min(head) == 3))
	{
		sa(data);
		rra(data);
		return ;
	}
	if (find_min(head) == 1 && find_max(head) == 2)
	{
		sa(data);
		ra(data);
		return ;
	}
	if (find_min(head) == 2 && find_max(head) == 3)
		sa(data);
	else if (find_max(head) == 1 && find_min(head) == 2)
		ra(data);
	else if (find_max(head) == 2 && find_min(head) == 3)
		rra(data);
}

void	ft_sort(t_data *data)
{
	if (is_sorted(&data->stack_a->head) == 0)
		return ;
	if (data->stack_a->len == 1)
		return ;
	if (data->stack_a->len == 2)
	{
		if (is_sorted(&data->stack_a->head) != 0)
			sa(data);
		return ;
	}
	if (data->stack_a->len == 3)
		mini_sort(data->stack_a, &data->stack_a->head, data);
	else
		ft_sorting_algo(data);
}
