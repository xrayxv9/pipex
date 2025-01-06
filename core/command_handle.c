/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:59:13 by xray              #+#    #+#             */
/*   Updated: 2025/01/06 09:01:15 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"

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

void	exec(char **command, char *cmd)
{
	(void)command;
	(void)cmd;
}
