/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:01:18 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 15:20:32 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
		c = c + 32;
	return (c);
}

/*#include <ctype.h>
int main (int ac, char **av)
{
	int i = 1;
	while (i != ac)
	{
		int j = 0;
		while (av[i][j] != '\0')
		{
			printf("%d\n", ft_tolower(av[i][j]));
			printf("La vraie fonction :");
			printf("%d\n", tolower(av[i][j]));
			j++;
		}
		i++;
	}
	return (0);
}*/