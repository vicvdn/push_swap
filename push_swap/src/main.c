/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:28:21 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/06 12:34:46 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
