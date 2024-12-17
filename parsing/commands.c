/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:24 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/17 15:09:30 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	ft_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	**cmd(char *av)
{
	char	**command;

	command = ft_split(av, ' ');
}
