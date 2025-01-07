/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:59:13 by xray              #+#    #+#             */
/*   Updated: 2025/01/07 13:56:52 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"
#include <unistd.h>

char	*does_exist(char *cmd, char **paths)
{
	char	*join;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	if (!paths)
		return (NULL);
	if (!(*paths))
		return (NULL);
	while (paths[i])
	{
		join = ft_strjoin(paths[i], cmd);
		if (!access(join, X_OK))
			return (join);
		free(join);
		i++;
	}
	return (NULL);
}

int	exec(char **command, char *cmd, char **env, int fds[4])
{
	int	pid;

	pid = fork();
	if (cmd && pid == 0)
	{
		dup2(fds[0], 0);
		dup2(fds[1], 1);
		close_all(fds[0], fds[1], fds[2]);
		execve(cmd, command, env);
		exit(1);
	}
	close_all(fds[0], fds[1], -1);
	return (pid);
}

int	final_exec(char **command, char *cmd, char **env, int fds[4])
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fds[0], 0);
		dup2(fds[1], 1);
		close_all(fds[0], fds[1], fds[2]);
		execve(cmd, command, env);
		exit(1);
	}
	close_all(fds[0], fds[1], fds[2]);
	return (pid);
}
