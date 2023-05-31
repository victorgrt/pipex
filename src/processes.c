/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:34:15 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/31 15:55:46 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_parent_process(char **av, char **envp, int *fd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		ft_print_error("fileout = -1 donc open failed");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fileout);
	execute(av[3], envp);
}

void	ft_child_process(char **av, char **envp, int *fd)
{
	int	filein;

	filein = open(av[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_print_error("filein = -1 donc open failed");
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(filein);
	close(fd[0]);
	close(fd[1]);
	execute(av[2], envp);
}
