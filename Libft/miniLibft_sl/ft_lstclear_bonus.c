/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:52:36 by marias-e          #+#    #+#             */
/*   Updated: 2022/12/12 12:56:56 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*temp;

	if (lst && del && *lst)
	{
		temp = *lst;
		while (temp)
		{
			*lst = (*lst)->next;
			ft_lstdelone(temp, del);
			temp = *lst;
		}
	}
}
