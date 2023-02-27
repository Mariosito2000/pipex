/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:55:28 by marias-e          #+#    #+#             */
/*   Updated: 2023/02/27 12:38:25 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include "../Libft/miniLibft_sl/libft.h"
# include "../Libft/get_next_line_sl/get_next_line.h"
# include "../Libft/ft_printf_sl/ft_printf.h"

typedef struct s_ls
{
	char	**env;
	char	**commands;
}	t_ls;

void		ft_exit(int reason);

char		**ft_manage_env(char **env);
void		ft_check_inputs(char **argv, char **path, char **commands);

void		ft_execute(int argc, char **argv, char **commands, char **env);
void		ft_manage_pids(pid_t *pid, int argc);

#endif