/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:52:26 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/19 15:53:19 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"
#include "../core/core.h"

int	main (int argc, char **argv, char **env)
{
	char	**paths;

	if (argc <= 4)
		return (0);
	if (!(*env))
		paths = NULL;
	else
		paths = get_paths(env);
	core(argv, paths, argc);
	free_all(paths);
}
