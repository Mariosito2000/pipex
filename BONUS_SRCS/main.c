/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:39:27 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/25 10:35:45 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**path;
	char	**commands;

	if (argc < 4 || !env || (argc < 5 && !ft_strncmp(argv[1], "here_doc", 9)))
		ft_exit(1);
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		commands = malloc(sizeof(char *) * (argc - 3));
		commands[argc - 4] = 0;
	}
	else
	{
		commands = malloc(sizeof(char *) * (argc - 2));
		commands[argc - 3] = 0;
	}
	path = ft_manage_env(env);
	ft_check_inputs(argv, path, commands);
	ft_execute(argc, argv, commands);
	ft_exit(0);
}
