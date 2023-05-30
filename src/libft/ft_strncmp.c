/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:47:02 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/15 14:07:06 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((b1[i] && b2[i]) && (b1[i] == b2[i] && i < n - 1))
		i++;
	return (b1[i] - b2[i]);
}

/*
#include <string.h>
int	main(int ac, char **av)
{
	(void) ac;
	printf("la vraie fonction :%d\n", strncmp(av[1], av[2], 7));
	printf("%d\n", ft_strncmp(av[1], av[2], 7));
	return (0);
}*/