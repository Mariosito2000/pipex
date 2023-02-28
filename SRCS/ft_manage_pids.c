/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_pids.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:33:17 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/28 13:46:44 by marias-e         ###   ########.fr       */
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

pid_t	*ft_pid_malloc(int argc)
{
	pid_t	*pid;

	pid = malloc(sizeof(pid_t) * (argc - 3));
	if (!pid)
		ft_exit(2);
	return (pid);
}
