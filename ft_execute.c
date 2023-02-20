/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:07 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/20 17:25:22 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(int argc, char **argv, char **commands)
{
	int		i;
	int		p[2];
	pid_t	*id;

	id = malloc(sizeof(pid_t) * (argc - 3));
	i = 0;
	if (pipe(p))
		ft_exit(2);

	(void)argv;
	while (i < argc - 3)
	{
/* 		id[i] = fork();
		waitpid(id[i], 0, 0); */
		if (/*  */!ft_strncmp(commands[i], "NO", 2))
		{
			(void)argv;
		}
		i++;
	}
}

/* 	p[0] = open(argv[1], O_RDONLY);
	p[1] = open(argv[argc - 1], O_WRONLY);

	dup2(p[0], 0);
	dup2(p[1], 1); */