/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:22:53 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/12 11:00:42 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(int c);

int	ft_write_di(int n)
{
	int				count;
	unsigned int	num;

	count = 1;
	num = n;
	if (n < 0)
	{
		write(1, "-", 1);
		num = -n;
	}
	if (num >= 10)
	{
		count = ft_write_di(num / 10);
		ft_putchar((num % 10) + '0');
		count++;
	}
	else
		ft_putchar(num + '0');
	if (n < 0)
		count++;
	return (count);
}

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}
