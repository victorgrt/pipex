/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:53:49 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/12 15:24:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	pid_t	child2;
	pid_t	child1;
	int		pipe_fd[2];
	int		status;

	if (ac != 5)
		ft_print_error("Error\nBad Arguments : \
            usage : ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	if (pipe(pipe_fd) == -1)
		ft_print_error("pipe(pipe_fd) == -1 donc pipe echec\n");
	ft_check_args(ac, av);
	child1 = fork();
	if (child1 < 0)
		ft_print_error("Error\nFork Error");
	if (child1 == 0)
		ft_child1(av[1], envp, pipe_fd, av[2]);
	child2 = fork();
	if (child2 < 0)
		ft_print_error("Error\nFork Error");
	if (child2 == 0)
		ft_child2(av[4], envp, pipe_fd, av[3]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	return (0);
}
