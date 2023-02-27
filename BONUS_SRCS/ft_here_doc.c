/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:28:00 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/27 12:16:31 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_set_i_value(char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 9))
		return (1);
	return (0);
}

void	ft_here_doc(char **argv)
{
	int		fd;
	char	*line;

	printf("limit = %s\n", argv[2]);
	fd = open(".temp", O_WRONLY | O_CREAT | O_APPEND | O_NOFOLLOW, 0777);
	if (fd < 0)
		ft_exit(2);
	ft_printf("pipe heredoc> ");
	line = get_next_line(STDIN_FILENO);
	while (line && (ft_strncmp(line, argv[2], ft_strlen(argv[2]) + 1)
			&& ft_strncmp(line, argv[2], ft_strlen(argv[2]) + 1) != '\n'))
	{
		ft_putstr_fd(line, fd);
		ft_printf("pipe heredoc> ");
		line = get_next_line(STDIN_FILENO);
	}
	close(fd);
	fd = open(".temp", O_RDONLY);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		unlink(".temp");
		ft_exit(2);
	}
	close(fd);
	unlink(".temp");
}

int	ft_check_here_doc(char **argv, int i)
{
	if (ft_strncmp(argv[1], "here_doc", 9))
		return (open(argv[i + 3],
				O_WRONLY | O_CREAT | O_TRUNC | O_NOFOLLOW, 0644));
	else
		return (open(argv[i + 3],
				O_WRONLY | O_CREAT | O_APPEND | O_NOFOLLOW, 0644));
}
