/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:15:15 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/27 11:16:38 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_set_terminator(char **path)
{
	int		i;
	char	*temp;

	i = 0;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		if (!path[i])
			ft_exit(2);
		free(temp);
		i++;
	}
}

char	**ft_manage_env(char **env)
{
	int		i;
	char	**path;

	path = 0;
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			path = ft_split(env[i] + 5, ':');
			if (!path)
				ft_exit(2);
			break ;
		}
		i++;
	}
	if (path)
		ft_set_terminator(path);
	else
		ft_exit(1);
	return (path);
}
