/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:34:25 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/23 10:39:44 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*destc;
	const char	*sourc;

	if (!dst && !src)
		return (0);
	i = 0;
	destc = dst;
	sourc = src;
	while (i < n)
	{
		destc[i] = sourc[i];
		i++;
	}
	return (dst);
}
