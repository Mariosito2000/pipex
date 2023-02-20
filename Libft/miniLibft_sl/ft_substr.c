/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:41:48 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/26 10:18:01 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	if (!s)
		return (ft_calloc(1, 1));
	if ((size_t)start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if ((unsigned int)len > ft_strlen(s) - (size_t)start)
		str = malloc((ft_strlen(s) - (size_t)start + 1) * sizeof(char));
	else
		str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (n < len && s[start])
	{
		str[n] = s[start];
		n++;
		start++;
	}
	str[n] = 0;
	return (str);
}
