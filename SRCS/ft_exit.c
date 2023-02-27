/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:43:44 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/27 10:55:59 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
* Exit function.
*
*	0 - clean exit
*	1 - manual error exit
*	2 - system error exit
*
* Parameters:
* reason  -  Exit reason.
*/
void	ft_exit(int reason)
{
	if (reason == 0)
		exit(0);
	else if (reason == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (reason == 2)
	{
		strerror(errno);
		exit(2);
	}
}
