/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:53:31 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 16:44:48 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*russel;
	const unsigned char	*faustin;
	size_t				i;

	russel = s1;
	faustin = s2;
	i = 0;
	while (i < n)
	{
		if (russel[i] != faustin[i])
			return (russel[i] - faustin[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
int	main(void)
{
	char	tab1[] = "Bonjouz";
	char	tab2[] = "Bonjour";
	printf("La vraie fonction :%d\n", memcmp(tab1, tab2, 7));
	printf("%d\n", ft_memcmp(tab1, tab2, 7));
	return (0);
}*/