/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:48:38 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/29 15:27:05 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_aux_count(char const *s, char c);

static size_t	ft_aux_iter(char const *s, char c, size_t i);

static size_t	ft_aux_len(char const *s, char c, size_t i);

static char		**ft_mem_error(char **array, size_t n);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	n;
	size_t	w;
	size_t	i;

	i = 0;
	n = 0;
	w = ft_aux_count(s, c);
	if (w == 0)
		return (ft_calloc(1, sizeof(char *)));
	array = malloc((w + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s && n < w)
	{
		while (s[i] && s[i] == c)
			i++;
		array[n] = ft_substr(s, (unsigned int)i, (ft_aux_len(s, c, i)));
		if (!array[n])
			return (ft_mem_error(array, n));
		i = ft_aux_iter(s, c, i);
		n++;
	}
	array[n] = 0;
	return (array);
}

static size_t	ft_aux_count(char const *s, char c)
{
	size_t	count;
	size_t	n;

	if (!s)
		return (0);
	count = 0;
	n = 0;
	while (s[n])
	{
		while (s[n] == c)
			n++;
		while (s[n] != c && s[n])
			n++;
		if (s[n - 1] != c)
			count++;
	}
	return (count);
}

static size_t	ft_aux_iter(char const *s, char c, size_t i)
{
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static size_t	ft_aux_len(char const *s, char c, size_t i)
{
	size_t	k;

	k = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		k++;
	}
	return (k);
}

static char	**ft_mem_error(char **array, size_t n)
{
	while (n > 0)
	{
		free(array[n - 1]);
		n--;
	}
	free(array);
	return (0);
}
