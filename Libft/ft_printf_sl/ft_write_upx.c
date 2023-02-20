/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_upx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:57:42 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/12 11:10:55 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_upx(unsigned int num, char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_write_upx(num / 16, "0123456789ABCDEF");
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
