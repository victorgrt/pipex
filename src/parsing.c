/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:58:14 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/31 15:58:48 by vgoret           ###   ########.fr       */
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

void	ft_check_args(int ac, char **av)
{
	int	tmp;

	if (ac != 5)
		ft_print_error("Error\nPlease Check Arguments\nParsing des Arguments");
	tmp = ft_check_existing_files(av[1], 0);
	close(tmp);
	tmp = ft_check_existing_files(av[4], 1);
	close(tmp);
}
