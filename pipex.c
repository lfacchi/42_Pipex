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

char *cmd_path_find(char **env, char *cmd)
{
	int		i;
	int		j;
	char	*build_path;
	char	**path_list;
	char	*aux;
	int		len;

	printf("%s:\n\n", cmd);
	i = j = 0;
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
		// free(path_list[j]);
		j++;
	}
	return(path_list[j]);
	// return(NULL);
}