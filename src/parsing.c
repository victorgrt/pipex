/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:58:14 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/25 18:52:10 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/* NOTES :
https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901

https://aurelienbrabant.fr/blog/an-introduction-to-unix-pipes
/bin/echo 'b o n j o u r' | tr -d ' '

http://www.cs.loyola.edu/~jglenn/702/S2005/Examples/dup2.html

pipefd[0] = reference a l'extremite de lecture
pipefd[1] = reference a l'extremite d'ecriture


Commandes : 
fork() // cree des childs
pipe()
dup2()
exec()
wait()
*/

int	ft_check_existing_files(char *av, int i)
{
	int	fd;

	if (i == 0)
		fd = open(av, O_RDONLY, 0777);
	if (i == 1)
		fd = open(av, O_RDONLY, 0777);
	if (fd == -1)
		ft_print_error("Error\nFile Not Found\nFile Descriptor Error");
	return (fd);
}

void	ft_check_args(int ac, char **av, int *fd)
{
	if (ac != 5)
		ft_print_error("Error\nPlease Check Arguments\nParsing des Arguments");
	if (pipe(fd) == -1)
		ft_print_error("pipe");
	ft_check_existing_files(av[1], 0);
	ft_check_existing_files(av[4], 1);
}

// int	main(int ac, char **av)
// {
// 	// pid_t	pipe_id;
// 	int		pipefd[2];
	

// 	ft_check_args(ac, av, pipefd);
// 	return (0);
// }