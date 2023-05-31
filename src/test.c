/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:35:07 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/31 15:55:15 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdlib.h>
// https://github.com/gabcollet/pipex/blob/master/srcs/pipex.c

// int	main(int ac, char **av, char **envp)
// {
// 	pid_t	pid;
// 	int		pipe_fd[2];

// 	if (ac != 5)
// 		ft_print_error("Error\nBad Arguments : usage 
// : ./pipex <file1> <cmd1> <cmd2> <file2>\n");
// 	if (pipe(pipe_fd) == -1)
// 	{
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		ft_print_error("pipe(pipe_fd) == -1 donc pipe echec\n");
// 	}
// 	ft_check_args(ac, av, pipe_fd);
// 	pid = fork();
// 	if (pid == -1)
// 		ft_print_error("Error\nFork Error");
// 	if (pid == 0)
// 		ft_child_process(av, envp, pipe_fd);
// 	waitpid(pid, NULL, 0);
// 	ft_parent_process(av, envp, pipe_fd);
// 	int i = 0;
// 	while (i <= 2)
// 	{
// 		close(pipe_fd[i]);
// 		i++;
// 	}
// 	return (0);
// }