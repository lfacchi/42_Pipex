/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:22:17 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/11/27 12:22:17 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_path_find(char **env, char *cmd)
{
	int		i;
	int		j;
	char	**path_list;

	i = 0; 
	j = 0;
	while(env[i] != NULL && ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	path_list= ft_split(env[i], ':');
	path_list[j] = ft_strtrim(path_list[j], "PATH=");
	while(path_list[j])
	{
		path_list[j] = ft_strjoin(path_list[j], "/");
		path_list[j] = ft_strjoin(path_list[j], cmd);
		if (access(path_list[j], F_OK) == 0 && access(path_list[j], X_OK) == 0)
			break;
		free(path_list[j]);
		j++;
	}
	return (path_list[j]);
}

char	**decode_cmd(char *arg)
{
	int		i;
	char	**cmd;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '\'' || arg[i] == '\"')
		{
			i++;
			while (arg[i] != '\'' && arg[i] != '\"' && arg[i] != '\0')
				i++;
		}
		else if (arg[i] == ' ')
			arg[i] = 1;
		i++;
	}
	cmd = ft_split(arg, 1);
	return (cmd);
}