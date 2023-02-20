/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:34:33 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/11 17:43:53 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_u(unsigned int u)
{
	char	c;
	int		count;

	count = 0;
	if (u >= 10)
	{
		count += ft_write_u(u / 10);
		c = (u % 10) + '0';
		write(1, &c, 1);
		count++;
	}
	if (u < 10)
	{
		c = u + '0';
		count++;
		write(1, &c, 1);
	}
	return (count);
}
