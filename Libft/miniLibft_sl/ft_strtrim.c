/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:21:33 by marias-e          #+#    #+#             */
/*   Updated: 2022/09/30 10:33:21 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	end;

	if (!s || !set)
		return (0);
	while (*s && ft_strchr(set, *s))
		s++;
	end = ft_strlen(s);
	while (*s && end && ft_strchr(set, s[end]))
		end--;
	return (ft_substr(s, 0, end + 1));
}
