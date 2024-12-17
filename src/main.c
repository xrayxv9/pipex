/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:52:26 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/17 16:27:11 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"

int	main (int argc, char **argv, char **env)
{
	char	**paths;
	int		i;

	if (argc == 1)
		return (0);
	i = 0;
	paths = get_paths(env);
	free_all(paths);
}
