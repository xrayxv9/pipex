/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:09:30 by xray              #+#    #+#             */
/*   Updated: 2024/12/11 01:39:49 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main (void)
{
    char *path = "/bin/ls";

    char *args[] = {"ls", NULL, NULL};

    if (execv(path, args) == -1) 
	{
        perror("exec");
        return (1);
    }
    return (0);
}
