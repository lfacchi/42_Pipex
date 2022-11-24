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

void start_child(char *argv, char **env, int *fd)
{
	int infile;

	infile = open(argv[1], O_RDONLY | O_CREAT , 0777);
	if (infile == -1)
		printf("ERROR\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO)
	close(fd[0]);
	start_command(argv[2], env);
}

void start_parent(char *argv, char **env, int *fd)
{
	int outfile;

	outfile = open(argv[5], O_WRONLY | O_CREAT, 0777);
	if (outfile == -1)
		printf("ERROR");
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	start_command(argv[3], env);
}

int main(int argc, char **argv, char **env)
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
		pipe(fd);
		if (fd == -1)
			printf("ERROR - 3\n");
		pid = fork();
		if (pid == -1)
			printf("ERROR - 4\n");
		if (pid == 0);
			start_child(argv, env, fd);
		waitpid(pid, NULL, 0);
		start_parent(argv, env, fd);
	}
	// c = ft_split(argv[2], ' ');
	// pid  = fork();
	// if (pid == 0)
	// {
	// 	fdout = open(argv[1], O_WRONLY /* | O_CREAT, 0777 */);
	// 	dup2(fdout, 1);
	// 	execvp(c[0],c);
	// }
	// {
	// 	if (!access(argv[1], F_OK))
	// 	{
	// 		fdin = open(argv[1], O_RDONLY /* | O_CREAT , 0777 */);
	// 		dup2(fdin , 0);
	// 		execvp(c[0],c);
	// 	}
	// 	// else
	// 	// 	printf("pipex: %s file or directory does not exist\n", argv[1]);

	// }
	// int i = -1;
	// while(env[++i])
	// 	printf("%s\n\n", env[i]);
	char *fullpath;
	fullpath = cmd_path_find(env, argv[1]);
	// printf("%s\n", fullpath);
	// printf("%s\n", fullpath);

}
