/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:13:50 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/21 10:59:50 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_aux_count(unsigned int u);

char	*ft_itoa(int n)
{
	unsigned int	c;
	char			*str;
	unsigned int	u;

	u = n;
	if (n < 0)
		u = -n;
	c = ft_aux_count(u);
	if (n < 0)
		c++;
	str = (char *) malloc ((c + 1) * sizeof(char));
	if (!str)
		return (0);
	str[c] = 0;
	c--;
	if (n < 0)
		str[0] = '-';
	while (u >= 10)
	{
			str[c] = (u % 10) + 48;
			u /= 10;
			c--;
	}
	str[c] = u + 48;
	return (str);
}

static unsigned int	ft_aux_count(unsigned int u)
{
	unsigned int	c;
	unsigned int	p;

	c = 1;
	p = 10;
	while (u > 9)
	{
		u = u / 10;
		c++;
	}
	return (c);
}
