/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:36:37 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/29 17:03:01 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n1;
	size_t	n2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	n1 = ft_strlen(s1);
	str = malloc(n1 + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	n2 = 0;
	while (n2 < n1)
	{
		str[n2] = s1[n2];
		n2++;
	}
	n1 = 0;
	while (s2[n1])
	{
		str[n2] = s2[n1];
		n2++;
		n1++;
	}
	str[n2] = s2[n1];
	return (str);
}
