/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:26:01 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/11/04 14:26:01 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		pid;

	if (argc != 5)
	{
		printf("error: number of arguments are wrong\n");
		exit(2);
	}
	else
	{
		if (pipe(fd) == -1)
			printf("ERROR - 3\n");
		pid = fork();
		if (pid == -1)
			printf("ERROR - 4\n");
		if (pid == 0)
			init_child(argv, env, fd);
		waitpid(pid, NULL, 0);
		pid = fork();
		if (pid == 0)
			init_parent(argv, env, fd);
	}
}
