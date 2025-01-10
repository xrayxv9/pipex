/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:51 by xray              #+#    #+#             */
/*   Updated: 2025/01/08 10:29:38 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"
#include <fcntl.h>

int	in(char *file)
{
	int	fd;
	int	pi[2];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("The file couldn't be opened\n", 2);
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

int	out(char *file, int i[4])
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		close_all(i[0], i[1], i[2]);
		ft_putstr_fd("The file couldn't be open successfully\n", 2);
		return (-1);
	}
	return (fd);
}

void	close_all(int fd, int fd2, int fd3)
{
	if (fd > -1)
		close(fd);
	if (fd2 > -1)
		close(fd2);
	if (fd3 > -1)
		close(fd3);
}
