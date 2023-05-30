/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:02:16 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 16:47:33 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (c == 0)
		return ((char *)&(s[len]));
	return (NULL);
}

/*#include <string.h>
int	main(void)
{
	char	tab[] = "Faustin lol ll tg";
	char	c = 'l';
	// char	*chr = ft_strchr(tab, c);
	// chr == 0 ? printf("rien\n") : printf("%s\n", ft_strchr(tab, c));
	printf("La vraie fonction :%s\n", strchr(tab, c));
	printf("%s", ft_strchr(tab, c));
	return (0);
}*/