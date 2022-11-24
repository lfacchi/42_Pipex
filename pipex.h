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
#include "42_libft/libft.h"
#include <fcntl.h>


typedef struct t_input
{
	int infile[2];
	int outfile[2];
};


char *cmd_path_find(char **env, char *cmd);