/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:18:48 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/19 12:16:22 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_select(char code, va_list args);

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format_select(format[i], args);
		}
		else
		{
			write (1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_format_select(char code, va_list args)
{
	int	count;

	if (code == 'c')
		count = ft_write_c(va_arg(args, int));
	if (code == 's')
		count = ft_write_s(va_arg(args, char *));
	if (code == 'p')
		count = ft_write_p(va_arg(args, void *));
	if (code == 'd' || code == 'i')
		count = ft_write_di(va_arg(args, int));
	if (code == 'u')
		count = ft_write_u(va_arg(args, unsigned int));
	if (code == 'x')
		count = ft_write_x(va_arg(args, unsigned int), "0123456789abcdef");
	if (code == 'X')
		count = ft_write_upx(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (code == '%')
	{
		write (1, "%%", 1);
		count = 1;
	}
	return (count);
}
