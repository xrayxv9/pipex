/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:51 by xray              #+#    #+#             */
/*   Updated: 2024/12/19 13:54:10 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"

int	in(char *file)
{
	int	fd;
	int	pi[2];
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("The file couldn't be opened", 2);
		if (pipe(pi) < 0)
		{
			perror("pipe didn't succeed");
			return (-1);
		}
		close(pi[1]);
		return (pi[0]);
	}
	return (fd);
}
