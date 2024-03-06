/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:06:02 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/09 13:06:58 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}

int	nb_elements(char **values)
{
	int	i;

	i = 0;
	while (values && values[i])
		i++;
	return (i);
}

int	nb_len(int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	if (nb < 0)
		i = 1;
	else
		i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_parse(int len, char **values, t_data *data, int i)
{
	int		nb;
	int		test;

	while (++i < len)
	{
		if (ft_strlen(values[i]) > 11)
			return (-1);
		nb = ft_atol(values[i]);
		test = ft_strncmp("0", values[i], 1);
		if ((nb_len(nb) != (int)ft_strlen(values[i]))
			|| (nb == 0 && test != 0) || nb > INT_MAX || nb < INT_MIN)
			return (-1);
		insert_end(&data->stack_a->head, &data->stack_a->tail, nb, data);
	}
	return (0);
}

int	ft_parsing(int ac, char **av, t_data *data)
{
	int		len;
	char	**values;

	if (ac == 2)
	{
		values = ft_split(av[1], ' ');
		if (values == NULL)
			return (-2);
		data->values = values;
		data->splitted = 1;
		len = nb_elements(values);
		if (is_double(values, data) == 1)
			return (ft_error(1), -1);
		if (ft_parse(len, values, data, -1) == -1)
			return (ft_error(1), -1);
	}
	else if (ac > 2)
	{
		data->splitted = 0;
		if (is_double(av, data) == 1)
			return (ft_error(1), -1);
		if (ft_parse(ac, av, data, 0) == -1)
			return (ft_error(1), -1);
	}
	return (0);
}
