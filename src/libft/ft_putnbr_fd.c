/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:15:08 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 15:22:18 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	modulo;
	long int	division;
	long int	longnb;	

	longnb = n;
	if (longnb < 0)
	{
		longnb = longnb * (-1);
		ft_putchar_fd('-', fd);
	}
	division = longnb / 10;
	modulo = longnb % 10;
	if (division != 0)
		ft_putnbr_fd(division, fd);
	ft_putchar_fd(48 + modulo, fd);
}

/*#include <limits.h>
int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
	return (0);
}*/