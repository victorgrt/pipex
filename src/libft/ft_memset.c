/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:18:23 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 14:33:38 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*
int main(void)
{
	char    tab[] = "Bonjour";
	char    x = 'o';
	ft_memset(tab, x, 3);
	printf("%s", tab);
	return (0);
}*/