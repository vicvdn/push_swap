/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:44:55 by vvaudain          #+#    #+#             */
/*   Updated: 2024/01/24 13:56:54 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static size_t	get_next_char_index(const char *s, char c)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (i);
}

size_t	ft_count_words(const char *s, char c)
{
	size_t	r;

	r = 0;
	while (*s && *s == c)
		s++;
	if (*s == 0)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			r++;
			while (*s == c)
				s++;
			if (*s == 0)
				return (r);
		}
		s++;
	}
	return (r + 1);
}

static void	ft_free_split(char **s)
{
	size_t	i;

	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	free(s);
}

static char	**ft_size_split(const char *s, char c, size_t *size)
{
	char	**tab;
	size_t	i;
	size_t	k;
	size_t	next;

	*size = ft_count_words(s, c);
	tab = (char **) ft_calloc(*size + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	k = -1;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		next = get_next_char_index(s + i, c);
		tab[++k] = ft_substr(s, i, next);
		if (tab[k] == NULL)
			return (ft_free_split(tab), NULL);
		i += next;
		while (s[i] == c && s[i])
			i++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	size_t	size;

	return (ft_size_split(s, c, &size));
}
