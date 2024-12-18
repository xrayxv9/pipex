/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:52:26 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/18 16:45:20 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"
#include "../core/core.h"

int	main (int argc, char **argv, char **env)
{
	char	**paths;
	char	**cmds;
	char	*cmd;

	if (argc <= 4)
		return (0);
	paths = get_paths(env);
	core(argv, paths);
	cmds = ft_split(argv[2], ' ');
	cmd = does_exist(cmds[0], paths);
	printf("path : %s\n", cmd);
	free(cmd);
	free_all(cmds);
	free_all(paths);
}
