/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:48:43 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 15:20:19 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	c2;

	c2 = c;
	if (c2 <= 'z' && c2 >= 'a')
		c2 = c2 - 32;
	return (c2);
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
            printf("%d\n", ft_toupper(av[i][j]));
            //printf("%d\n", toupper(av[i][j]));
            j++;
        }
        i++;
    }
    return (0);
}*/