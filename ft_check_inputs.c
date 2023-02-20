/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:42:48 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/20 16:37:36 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_check_command(char *command, char **path)
{
	int		i;
	char	*temp;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], command);
		if (temp && !access(temp, F_OK))
		{
			if (!access(temp, X_OK))
				return (temp);
			perror(command);
		}
		if (temp)
			free(temp);
		i++;
	}
	perror(command);
	return ("NO");
}

void	ft_check_inputs(char **argv, char **path, char **commands)
{
	int		i;
	char	**com;

	i = 2;
	while (argv[i + 1])
	{
		com = ft_split(argv[i], ' ');
		if (com)
		{
			commands[i - 2] = ft_check_command(com[0], path);
			ft_free_split(com);
		}
		i++;
	}
	if (access(argv[1], R_OK))
		perror(argv[1]);
	if (access(argv[i], W_OK))
		perror(argv[i]);
}
