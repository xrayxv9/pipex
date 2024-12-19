/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:27:23 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/19 15:56:38 by cmorel           ###   ########.fr       */
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
		printf("test core\n");
		cmd = does_exist(command[0], paths);
		if (cmd)
			printf("command : %s, cmd : %s\n\n", command[0], cmd);
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
	i++;
	main_loop(av, paths, size);
	return (1);
}
