/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:59:13 by xray              #+#    #+#             */
/*   Updated: 2024/12/18 16:34:18 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"

char	*does_exist(char *cmd, char **paths)
{
	char	*join;
	int		i;

	i = 0;
	if (!access(cmd, X_OK))
		return (cmd);
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
