/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:26:40 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/11/04 14:26:40 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../42_libft/libft.h"
#include <fcntl.h>

typedef struct s_proc
{
	char	**argv;
	char	**env;
	int		*fd;
	int		i_cmd;
}t_proc;

char	*cmd_path_find(char **env, char *cmd);
void	init_child(char **argv, char **env, int *fd);
void	init_parent(char **argv, char **env, int *fd);
void	exec_cmd(char *cmd, char **env);
void	check_spaces(char *cmd);
void	trans_space(char **cmd);
char	**decode_cmd(char *arg);
