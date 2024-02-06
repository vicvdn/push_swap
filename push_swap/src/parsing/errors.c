/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:37 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/01 12:44:43 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(int error_num)
{
	if (error_num == 1)
		ft_printf("Error\n");
	if (error_num == 2)
		ft_printf("Allocation issue.");
}
