/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:36:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/12 17:11:40 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	verif_path(char *path, char **paths, char *join_path)
{
	int i = 0;

	if (access(path, X_OK) != 0)
	{
		while (paths[i])
		{
			printf("paths[%d] %s\n", i, paths[i]);
			i++;
		}
		printf("path %s\njoin_path %s\n", path, join_path);
	}
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*join_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		join_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(join_path, cmd);
		free(join_path);
		if (access(path, F_OK) == 0)
		{
			i = -1;
			while (paths[++i])
				free(paths[i]);
			free(paths);
			printf("path %s\n", path);
			return (path);
		}
		free(path);
		i++;
	}
	if (paths)
	{
		i = -1;
		while (paths[++i])
			free(paths[i]);
		free(paths);
	}
	// ft_print_error("Error de path");
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
		path = ft_strdup(cmd[0]);
	else
		path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		ft_print_error("Chemin vers la commande inconnu");
	}
	if (execve(path, cmd, envp) == -1)
		ft_print_error("execve");
}
