/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:47:38 by xray              #+#    #+#             */
/*   Updated: 2025/01/06 08:54:18 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CORE_H
# define CORE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../includes/libft/libft.h"
# include "../parsing/parsing.h"

int		in(char *file);

int		core(char **av, char **paths, const int size);

char	*does_exist(char *cmd, char **paths);

void	exec(char **command, char *cmd);


#endif 
