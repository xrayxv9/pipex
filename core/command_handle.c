/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:59:13 by xray              #+#    #+#             */
/*   Updated: 2024/12/19 15:55:51 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"

char	*does_exist(char *cmd, char **paths)
{
	char	*join;
	int		i;

	i = 0;
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
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
