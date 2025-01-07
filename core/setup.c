/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:46 by cmorel            #+#    #+#             */
/*   Updated: 2025/01/07 13:56:30 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "core.h"
#include <unistd.h>

int	*setup(int i[4], int fd)
{
	int	p[2];

	pipe(p);
	i[0] = fd;
	i[1] = p[1];
	i[2] = p[0];
	return (i);
}

void	fill(int *pids, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pids[i] = -1;
		i++;
	}
}

void	handle_error(int l[4])
{
	ft_putstr_fd("Command not found\n", 2);
	close_all(l[0], l[1], -1);
}
