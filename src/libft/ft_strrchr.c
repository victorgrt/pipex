/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:05 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/15 14:08:50 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return (&((char *)s)[len]);
		len--;
	}
	return (NULL);
}

/*#include <string.h>
int	main(void)
{
	char	tab[] = "abbbbbbbbbbbb";
	char	c = 'a';
	// char	*chr = ft_strchr(tab, c);
	// chr == 0 ? printf("rien\n") : printf("%s\n", ft_strchr(tab, c));
	printf("La vraie fonction :%s\n", strrchr(tab, c));
	printf("%s", ft_strrchr(tab, c));
	return (0);
}*/