/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:07 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/24 15:47:54 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(char **argv, char **commands, int i, int *fd)
{
	char	**com_split;
	int		f;

	com_split = ft_split(argv[i + 2], ' ');
	if (!com_split)
		ft_exit(1);
	close(fd[0]);
	if (!argv[i + 4] && !access(argv[i + 3], W_OK))
	{
		f = open(argv[i + 3], O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW);
		if (f == -1)
			ft_exit(2);
		if (dup2(f, STDOUT_FILENO) == -1)
			ft_exit(2);
		close(f);
	}
	else if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_exit(2);
	close(fd[1]);
	if (!ft_strncmp(commands[i], "NO", 3) || (i == 0 && access(argv[1], R_OK))
		|| (!argv[i + 4] && access(argv[i + 3], W_OK)))
		ft_exit(0);
	else
		if (execve(commands[i], com_split, 0))
			ft_exit(2);
}

static void	ft_father(int *fd)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_exit(2);
	close(fd[0]);
}

static void	ft_open_infile(char **argv, int	*j)
{
	int	i;

	*j = 0;
	if (!access(argv[1], R_OK))
	{
		i = open(argv[1], O_RDONLY);
		if (i == -1)
			ft_exit(2);
		if (dup2(i, STDIN_FILENO) == -1)
			ft_exit(2);
		close(i);
	}
}

void	ft_execute(int argc, char **argv, char **commands)
{
	int		i;
	int		fd[2];
	pid_t	*pid;

	pid = malloc(sizeof(pid_t) * (argc - 3));
	ft_open_infile(argv, &i);
	while (i < argc - 3)
	{
		if (pipe(fd))
			ft_exit(2);
		pid[i] = fork();
		if (pid[i] == -1)
			ft_exit(2);
		if (pid[i] == 0)
			ft_child(argv, commands, i, fd);
		else
			ft_father(fd);
		i++;
	}
	i = 0;
	while (i < argc - 3)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
}
