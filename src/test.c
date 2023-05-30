/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:35:07 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/30 12:09:42 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdlib.h>
// https://github.com/gabcollet/pipex/blob/master/srcs/pipex.c

void	execute(char *cmd, char **envp)
{
	char *command_args[] = { "/bin/sh", "-c", cmd, NULL };

    // Exécution de la commande en utilisant execve
    execve("/bin/sh", command_args, envp);

    // Si execve réussit, le code ci-dessous ne sera pas atteint
    // En cas d'erreur, afficher un message et quitter le processus
    perror("execve");
    exit(EXIT_FAILURE);
}

void	ft_parent_process(char **av, char **envp, int *fd)
{
	int	fileout;
	
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		ft_print_error("fileout = -1 donc open failed");
	dup2(fd[0], STDIN_FILENO); //on dup les fd
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], envp); //fonction qui execute
}

void	ft_child_process(char **av, char **envp, int *fd)
{
	int	filein;

	filein = open(av[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_print_error("filein = -1 donc open failed");
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO); //on dup le fd
	close(fd[0]);
	execute(av[2], envp); //fonction qui execute
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (ac != 5)
	ft_print_error("Error\nBad Arguments : usage : ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	if (pipe(pipe_fd) == -1)
		ft_print_error("pipe(pipe_fd) == -1 donc pipe echec\n");
	ft_check_args(ac, av, pipe_fd);
	pid = fork();
	if (pid == -1)
		ft_print_error("Error\nFork Error");
	if (pid == 0)
		ft_child_process(av, envp, pipe_fd);
	waitpid(pid, NULL, 0);
	ft_parent_process(av, envp, pipe_fd);
	return (0);
}


/*static void	get_path_info(t_ppipex ppxi, char **envp)
{
	while (envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			ppxi->path = ft_split((*envp + 5), ':');
			break ;
		}
		++envp;
	}
}
*/

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	while ((*s1 || *s2) && (n > 0))
// 	{
// 		if (*s1 != *s2)
// 			return ((unsigned char)*s1 - (unsigned char)*s2);
// 		s1++;
// 		s2++;
// 		n--;
// 	}
// 	return (0);
// }

// char	*find_path(char **envp)
// {
// 	while (ft_strncmp("PATH", *envp, 4))
// 		envp++;
// 	return (*envp + 5);
// }