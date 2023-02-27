/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_pids.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:33:17 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/27 11:39:34 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_manage_pids(pid_t *pid, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	if (pid)
		free(pid);
}
