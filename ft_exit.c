/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:43:44 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/16 16:51:58 by marias-e         ###   ########.fr       */
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
		write(1, "Error", 5);
		exit(0);
	}
	else if (reason == 2)
	{
		perror("Error");
		exit(0);
	}
}
