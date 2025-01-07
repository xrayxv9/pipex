/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:52:26 by cmorel            #+#    #+#             */
/*   Updated: 2025/01/07 13:55:54 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"
#include "../core/core.h"
#include <sys/wait.h>

int	free_all_pids(int *pids, int size)
{
	int	i;
	int	status;

	i = 0;
	while (i < size - 3)
	{
		if (pids[i] >= 0)
		{
			waitpid(pids[i], &status, 0);
		}
		i++;
	}
	free(pids);
	return (status);
}

int	main(int argc, char **argv, char **env)
{
	char	**paths;
	int		*pids;

	if (argc <= 4)
		return (0);
	if (!(*env))
		paths = NULL;
	else
		paths = get_paths(env);
	pids = core(argv, paths, argc, env);
	if (paths)
		free_all(paths);
	free_all_pids(pids, argc);
	return (0);
}
