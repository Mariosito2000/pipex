/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:24:30 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/11 17:52:54 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int			ft_write_p(void *pointer);
int			ft_printf(char const *format, ...);
int			ft_write_c(int c);
int			ft_write_s(char *string);
int			ft_write_x(unsigned int num, char *base);
int			ft_write_upx(unsigned int num, char *base);
int			ft_write_u(unsigned int u);
int			ft_write_di(int num);
size_t		ft_strlen(const char *str);

#endif
