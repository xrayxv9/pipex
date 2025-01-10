/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:47:38 by xray              #+#    #+#             */
/*   Updated: 2025/01/08 10:21:26 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CORE_H
# define CORE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../parsing/parsing.h"
# include "../includes/libft/libft.h"

int		in(char *file);

int		*core(char **av, char **paths, const int size, char **env);

char	*does_exist(char *cmd, char **paths);

int		exec(char **command, char *cmd, char **env, int fds[3]);

void	close_all(int fd, int fd2, int fd3);

int		*setup(int i[4], int fd);

int		out(char *file, int i[4]);

int		final_exec(char **command, char *cmd, char **env, int fds[4]);

void	fill(int *pids, int len);

void	handle_error(int l[4]);

#endif 
