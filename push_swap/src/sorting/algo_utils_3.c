/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:29:16 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/05 15:17:45 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	get_max(t_node **head)
{
	t_node	*cur_node;
	int		max;

	cur_node = (*head);
	max = INT_MIN;
	while (cur_node != NULL)
	{
		if (cur_node->data > max)
			max = cur_node->data;
		cur_node = cur_node->next;
	}
	return (max);
}

int	compute_min(t_node **head)
{
	int		min;
	t_node	*cur_node;

	cur_node = (*head);
	min = INT_MAX;
	while (cur_node != NULL)
	{
		if (cur_node->data < min)
			min = cur_node->data;
		cur_node = cur_node->next;
	}
	return (min);
}
