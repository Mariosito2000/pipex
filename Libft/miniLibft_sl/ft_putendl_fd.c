/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:39:45 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/29 16:43:02 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	n;

	if (!s || !fd)
		return ;
	n = 0;
	while (s[n])
		n++;
	write(fd, s, n);
	write(fd, "\n", 1);
	return ;
}
