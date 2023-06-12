/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:53:46 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/12 16:28:47 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include "src/libft/libft.h"

/* Parsing */
void	ft_check_args(int ac, char **av);
int		ft_check_existing_files(char *av, int i);

/* Processes */
void	ft_child1(char *av, char **envp, int *fd, char *cmd);
void	ft_child2(char *av, char **envp, int *fd, char *cmd);

/* Execute */
void	execute(char *cmd, char **envp);

/* Printer */
void	ft_print_error(char *str);

#endif