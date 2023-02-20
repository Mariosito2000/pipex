/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:23:50 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/12 13:23:56 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_s(char *string)
{
	int	count;

	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (string[count])
	{
		write (1, &string[count], 1);
		count++;
	}
	return (count);
}
