/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:45:10 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/12 11:05:20 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_x(unsigned int num, char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_write_x(num / 16, "0123456789abcdef");
		write(1, &base[num % 16], 1);
		count++;
	}
	if (num < 16)
	{
		count++;
		write(1, &base[num % 16], 1);
	}
	return (count);
}
