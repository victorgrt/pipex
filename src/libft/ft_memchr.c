/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:38:27 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/15 14:08:15 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*new;
	size_t				i;

	new = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (new[i] == (unsigned char)c)
			return ((void *)new + i);
		i++;
	}
	return (NULL);
}

/*#include <string.h>
int	main(void)
{
	char	tab[] = "Bonjour Russel";
	char	x = 'j';
	printf("La vraie fonction : %p\n", memchr(tab, x, 16));
	printf("%p\n", ft_memchr(tab, x, 16));
	return (0);
}*/