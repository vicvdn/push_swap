/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:28:21 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/07 11:52:55 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	print_list(t_node **head)
// {
// 	t_node	*cur_node;

// 	if (head == NULL)
// 	{
// 		ft_printf("empty list");
// 		return ;
// 	}
// 	cur_node = (*head);
// 	while (cur_node != NULL)
// 	{
// 		ft_printf("address: %p\n", cur_node);
// 		ft_printf("data : %d\n", cur_node->data);
// 		ft_printf("prev-> %p\n", cur_node->prev);
// 		ft_printf("next-> %p\n", cur_node->next);
// 		ft_printf("\n");
// 		cur_node = cur_node->next;
// 	}
// }

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 0 || ac == 1)
		return (0);
	create_stacks(&data);
	if (ft_parsing(ac, av, &data) == -1)
		return (ft_free_all(&data), -1);
	ft_sort(&data);
	ft_free_all(&data);
	return (0);
}
