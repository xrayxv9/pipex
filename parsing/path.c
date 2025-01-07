/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:42:29 by cmorel            #+#    #+#             */
/*   Updated: 2025/01/07 14:01:18 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
#include <stdlib.h>

char	**reformat_all(char **s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i])
	{
		tmp = ft_strjoin(s[i], "/");
		free(s[i]);
		s[i] = tmp;
		i++;
	}
	return (s);
}

char	*reformat(char *s)
{
	int		i;
	int		len;
	char	*reform;

	i = 0;
	len = ft_strlen(s) - 4;
	if (len <= 0)
		return (NULL);
	reform = ft_calloc(len, sizeof(char));
	if (!reform)
		return (NULL);
	while (s[i + 5])
	{
		reform[i] = s[i + 5];
		i++;
	}
	free(s);
	return (reform);
}

char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			paths = ft_split(env[i], ':');
			break ;
		}
		i++;
	}
	if (!paths)
		return (paths);
	paths[0] = reformat(paths[0]);
	paths = reformat_all(paths);
	return (paths);
}
