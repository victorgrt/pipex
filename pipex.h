/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:53:46 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/30 17:52:02 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
# include <unistd.h>
#include <fcntl.h>
#include "src/libft/libft.h"

/* Parsing */
void	ft_check_args(int ac, char **av, int *fd);
int		ft_check_existing_files(char *av, int i);

/* Processes */
void	ft_parent_process(char **av, char **envp, int *fd);
void	ft_child_process(char **av, char **envp, int *fd);

/* Execute */
void	execute(char *cmd, char **envp);

/* Printer */
void	ft_print_error(char *str);

#endif