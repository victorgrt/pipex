/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:36:12 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/30 18:07:03 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (path[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		ft_print_error("!path not found");
	}
	if (execve(path, cmd, envp) == -1)
		ft_print_error("execve");
}

// void	execute(char *cmd, char **envp)
// {
// 	char	*executable = NULL;
// 	char	*command_args[] = { NULL, "-c", cmd, NULL };

// 	// Recherche du chemin d'accès de l'interpréteur de commandes
// 	char	*path = getenv("PATH");
// 	if (path)
// 	{
// 		char	**path_dirs = ft_split(path, ':');
// 		for (int i = 0; path_dirs[i] != NULL; i++)
// 		{
// 			char	*temp1 = ft_strjoin(path_dirs[i], "/");
// 			char	*temp2 = ft_strjoin(temp1, "sh");
// 			free(temp1);
// 			if (access(temp2, X_OK) == 0)
// 			{
// 				executable = temp2;
// 				break;
// 			}
// 			free(temp2);
// 		}
// 		// Libérer la mémoire allouée pour path_dirs
// 		// ...
// 	}

// 	// Exécution de la commande en utilisant execve
// 	if (executable && execve(executable, command_args, envp) == -1)
// 	{
// 		perror("execve");
// 		exit(EXIT_FAILURE);
// 	}
// }


// void	execute(char *cmd, char **envp)
// {
// 	char *command_args[] = { "/bin/sh", "-c", cmd, NULL };

//     // Exécution de la commande en utilisant execve
//     execve("/bin/sh", command_args, envp);

//     // Si execve réussit, le code ci-dessous ne sera pas atteint
//     // En cas d'erreur, afficher un message et quitter le processus
//     perror("execve");
//     exit(EXIT_FAILURE);
// }

// void	execute(char *cmd, char **envp)
// {
// 	char	*path;
// 	char	**path_dirs;
// 	char	*splited;
// 	int		i;

// 	path = NULL;
// 	path_dirs = NULL;
// 	i = 0;

// 	//tester si argument == chemin directement
// 	while (envp[i] != NULL)
// 	{
// 		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
// 		{
// 			path = ft_strdup(envp[i] + 5);
// 			break;
// 		}
// 		i++;
// 	}
// 	if (path == NULL)
// 	{
// 		ft_print_error("PATH variable not found");
// 	}
// 	path_dirs = ft_split(path, ':');

// 	i = 0;
// 	while (path_dirs[i])
// 	{
// 		splited = ft_strjoin(path_dirs[i], "/");
// 		splited = ft_strjoin(splited, cmd);
// 		if (access(splited, F_OK) == 0)
// 		{
// 			printf("access == 0");
// 			break;
// 		}
// 		i++;
// 	}
// 	if (!splited)
// 	{
// 		ft_print_error("ici c'est paris");
// 	}
// 	i = 0;
// 	while (splited[i])
// 	{
// 		if (splited[i] == ' ')
// 		{
// 			splited[i] = '\0';
// 			// printf("splited : %s\n", splited);
// 			break;
// 		}
// 		i++;

// 	}
// 	printf("splited %s\n", splited);
// 	// execve(splited, (char *[]){splited, NULL}, envp);
// }