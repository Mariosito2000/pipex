/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:02:04 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/23 11:59:37 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		n;

	n = ft_strlen(s1);
	str = (char *) malloc(n + 1);
	if (!str)
		return (0);
	n = 0;
	while (s1[n])
	{
		str[n] = s1[n];
		n++;
	}
	str[n] = 0;
	return (str);
}
