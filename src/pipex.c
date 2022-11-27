/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:52:50 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/11/23 23:52:50 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void init_child(char **argv, char **env, int *fd)
{
	int infile;

	infile = open(argv[1], O_RDONLY | O_CREAT , 0777);
	if (infile == -1)
		perror("pipex");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	exec_cmd(argv[2], env);
}

void init_parent(char **argv, char **env, int *fd)
{
	int outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT| O_TRUNC , 0644);
	if (outfile == -1)
	// 	exit(0);
		perror("pipex");
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	// if (cmd_path_find(env, argv[2]) == NULL)
	// 	exit(EXIT_FAILURE);
	close(fd[1]);
	exec_cmd(argv[3], env);
}
// void start_parent(char **argv, char **env, int *fd)
// {
// 	int outfile;

// 	outfile = open(argv[4], O_WRONLY | O_CREAT, 0777);
// 	if (outfile == -1
// 	// 	exit(0);
// 		perror("pipex");
// 	dup2(outfile, STDOUT_FILENO);
// 	dup2(fd[0], STDIN_FILENO);
// 	close(fd[1]);
// }

void exec_cmd(char *cmd, char **env)
{
	char *cmd_path;
	char **cmd_list;

	cmd_list = decode_cmd(cmd);
	cmd_path = cmd_path_find(env, cmd_list[0]);
	if (!cmd_path)
		perror("pipex");
	execve(cmd_path, cmd_list, env);
}
