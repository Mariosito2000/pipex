/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:42:48 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/24 15:31:09 by marias-e         ###   ########.fr       */
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
		if (!temp)
			ft_exit(1);
		if (!access(temp, F_OK))
			if (!access(temp, X_OK))
				return (temp);
		if (temp)
			free(temp);
		i++;
	}
	perror(command);
	return ("NO");
}

static void	ft_write_failure(char **argv, char **commands, int i)
{
	if (commands[i - 3])
		free(commands[i - 3]);
	commands[i - 3] = ft_strdup("NO");
	if (!commands[i - 3])
		ft_exit(1);
	perror(argv[i]);
}

static void	ft_check_inputs_aux(char **argv, char **path,
		char **commands, int i)
{	
	char	**com;

	while (argv[i + 1])
	{
		com = ft_split(argv[i], ' ');
		if (!com)
			ft_exit(1);
		if (argv[i + 2])
		{
			commands[i - 2] = ft_check_command(com[0], path);
			ft_free_split(com);
		}
		i++;
	}
	if (access(argv[i], W_OK))
		ft_write_failure(argv, commands, i);
	else if (i != 3 || !access(argv[1], R_OK))
		commands[i - 3] = ft_check_command(com[0], path);
	ft_free_split(com);
}

void	ft_check_inputs(char **argv, char **path, char **commands)
{
	int		i;

	i = 2;
	if (access(argv[1], R_OK))
	{
		commands[0] = ft_strdup("NO");
		if (!commands[0])
			ft_exit(1);
		perror(argv[1]);
		i++;
	}
	ft_check_inputs_aux(argv, path, commands, i);
}
