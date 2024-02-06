/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:02:04 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/05 11:07:32 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_node(t_node *node)
{
	if (node->dist != NULL)
		free(node->dist);
	if (node->op_count != NULL)
		free(node->op_count);
	free(node);
}

void	ft_free_all(t_data *data)
{
	if (data)
	{
		if (data->stack_b != NULL)
		{
			ft_free_stack(&data->stack_b->head, &data->stack_b->tail);
			free(data->stack_b);
		}
		if (data->stack_a != NULL)
		{
			ft_free_stack(&data->stack_a->head, &data->stack_a->tail);
			free(data->stack_a);
		}
		if (data->splitted == 1)
			ft_free_tab(data->values);
	}
}
