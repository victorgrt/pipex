/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:35:07 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/24 16:27:58 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_cmd_path(char *str)
{
	
}

void	ft_exec_cmd(char *cmd)
{
	char	*path;

	path = ft_cmd_path(cmd);
	if (execve(path) == -1)
	{
		ft_print_error("Error\nZsh Command Not Found ");
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		ft_print_error("pipe(pipe_fd) == -1 donc pipe echec\n");
	printf("fd 1: %d\tfd 2 : %d\n", pipe_fd[0], pipe_fd[1]);
	ft_check_args(ac, av, pipe_fd);
	pid = fork();
	if (pid == -1)
		ft_print_error("Error\nFork Error");
	else if (pid == 0) //processus fils
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execvp(av[1], &av[1]);
		perror("execvp");
		ft_print_error("Error lors de l'execution de la commande");
	}
	else //processus pere
	{
		close(pipe_fd[1]);
		wait(NULL);
		close(pipe_fd[0]);
	}
}