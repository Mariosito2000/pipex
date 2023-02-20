/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:08:23 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/13 13:26:02 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*strchar;
	size_t			n;

	n = 0;
	strchar = (unsigned char *) str;
	while (n < len)
	{
		strchar[n] = c;
		n++;
	}
	return (str);
}
