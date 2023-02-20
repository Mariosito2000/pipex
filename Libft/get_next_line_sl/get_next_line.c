/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:21:22 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/01 13:04:14 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_aux_stash(char *stash, char *buffer, int count);

static char	*ft_fill_stash(char *stash, int fd);

static char	*ft_fill_line(char *stash);

static char	*ft_fix_stash(char *stash, size_t len);

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stash[1024];

	if (fd < 0)
		return (0);
	stash[fd] = ft_fill_stash(stash[fd], fd);
	if (!stash[fd])
		return (0);
	line = ft_fill_line(stash[fd]);
	if (!line)
		return (0);
	stash[fd] = ft_fix_stash(stash[fd], (ft_strlen_gnl(line)));
	return (line);
}

static char	*ft_fill_stash(char *stash, int fd)
{
	char	*buffer;
	int		count;

	count = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		stash = ft_aux_stash(stash, buffer, count);
		if (!stash)
		{
			free(buffer);
			return (0);
		}
		if (ft_strchr_mod(stash, '\n') != -1)
			break ;
	}
	if (buffer)
		free(buffer);
	return (stash);
}

static char	*ft_aux_stash(char *stash, char *buffer, int count)
{
	char	*temp;

	if (count == -1 || (count == 0 && !stash))
	{
		if (stash)
			free(stash);
		return (0);
	}
	if (count == 0 && stash)
		return (stash);
	buffer[count] = 0;
	if (!stash)
		stash = ft_strdup_gnl("");
	temp = stash;
	stash = ft_strjoin_gnl(stash, buffer);
	free(temp);
	return (stash);
}

static char	*ft_fill_line(char *stash)
{
	char	*line;
	int		n;

	n = ft_strchr_mod(stash, '\n');
	if (n >= 0)
		line = ft_substr_gnl(stash, 0, n + 1);
	else
		line = ft_strdup_gnl(stash);
	return (line);
}

static char	*ft_fix_stash(char *stash, size_t len)
{
	char	*temp;

	if (ft_strchr_mod(stash, '\n') == -1
		|| (unsigned int)ft_strchr_mod(stash, '\n') == ft_strlen_gnl(stash) - 1)
	{
		free(stash);
		stash = 0;
	}
	else
	{
		temp = stash;
		stash = ft_substr_gnl(stash, len, ft_strlen_gnl(stash));
		free(temp);
	}
	return (stash);
}
