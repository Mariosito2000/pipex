/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:03:17 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/01 13:03:42 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE	1

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *s);
char		*ft_strdup_gnl(const char *str);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
int			ft_strchr_mod(const char *s, int c);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);

#endif
