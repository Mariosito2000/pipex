/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:15:50 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/22 12:45:10 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	srclen;

	srclen = ft_strlen(src);
	n = 0;
	if (!dstsize)
		return (srclen);
	while (n < dstsize - 1 && src[n])
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = 0;
	return (srclen);
}
