/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:34:12 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/17 18:50:03 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	if ((nmemb > sizeof(char) * __INT_MAX__)
		|| (size > sizeof(char) * INT_MIN))
		return (NULL);
	i = 0;
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

/*#include <unistd.h>

int    main(void)
{
	char    *tab1;
	char    *tab2;
	size_t    i;
	size_t    nmembalt;

	nmembalt = 10;
	tab1 = ft_calloc(nmembalt, sizeof(char));
	tab2 = calloc(nmembalt, sizeof(char));
	i = 0;
	while (i < nmembalt)
	{
		write(1, &tab1[i], 1);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (i < nmembalt)
	{
		write(1, &tab2[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}*/

/*#include <stdlib.h>
int	main(void)
{
	printf("%p\n", ft_calloc(5, 1));
	printf("%p\n", calloc(5, 1));
	return (0);
}*/