/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:27:23 by cmorel            #+#    #+#             */
/*   Updated: 2025/01/07 14:00:35 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"
#include <unistd.h>

int	last_exec(char	**av, char **paths, int l[4], char **env)
{
	char	**command;
	char	*cmd;
	int		pid;
	int		fd;

	fd = out(av[l[3] - 1]);
	if (fd < 0)
		return (-1);
	l[0] = l[2];
	l[1] = fd;
	l[2] = -1;
	pid = -1;
	command = ft_split(av[l[3] - 2], ' ');
	cmd = does_exist(command[0], paths);
	pid = final_exec(command, cmd, env, l);
	free_all(command);
	free(cmd);
	return (pid);
}

int	*main_loop(char **av, char **paths, int l[4], char **env)
{
	char	**command;
	char	*cmd;
	int		i;
	int		*pids;

	pids = malloc((l[3] - 3) * sizeof(int));
	fill(pids, l[3] - 3);
	i = 0;
	setup(l, l[0]);
	while ((l[3] - 4) > i)
	{
		command = ft_split(av[i + 2], ' ');
		cmd = does_exist(command[0], paths);
		pids[i] = exec(command, cmd, env, l);
		if (i < (l[3] - 5))
			setup(l, l[2]);
		free_all(command);
		free(cmd);
		i++;
	}
	pids[i] = last_exec(av, paths, l, env);
	return (pids);
}

int	*core(char **av, char **paths, const int size, char **env)
{
	int	fd;
	int	i;
	int	*pids;
	int	l[4];

	i = 1;
	fd = in(av[i]);
	l[0] = fd;
	l[3] = size;
	i++;
	pids = main_loop(av, paths, l, env);
	return (pids);
}
