/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:27:23 by cmorel            #+#    #+#             */
/*   Updated: 2025/01/06 09:16:22 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"
#include <unistd.h>

void	main_loop(char **av, char **paths, int size)
{
	char	**command;
	char	*cmd;
	int		i;

	i = 0;
	while ((size - 4) > i)
	{
		command = ft_split(av[i + 2], ' ');	
		cmd = does_exist(command[0], paths);
		if (cmd)
			exec(command, cmd);
		free_all(command);
		free(cmd);
		i++;
	}
}

int	core(char **av, char **paths, const int size)
{
	int	fd;
	int	i;
	int	pids[size + 1];
	
	pids[size] = -2;
	i = 1;
	(void)paths;
	fd = in(av[i]);
	dup2(fd, 0);
	close(fd);
	i++;
	main_loop(av, paths, size);
	return (1);
}
