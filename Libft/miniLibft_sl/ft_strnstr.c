/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:26:47 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/29 16:36:29 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	n;
	unsigned int	i;

	if (len == 0 && !haystack)
		return (0);
	n = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[n] != 0 && n < len)
	{
		i = 0;
		while (haystack[n] == needle[i])
		{
			if (n == len)
				return (0);
			i++;
			n++;
			if (needle[i] == 0)
				return ((char *)haystack + n - i);
		}
		n = n - i;
		n++;
	}
	return (0);
}
