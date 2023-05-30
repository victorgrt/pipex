/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:42:14 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/15 15:50:00 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && len == 0)
		return (0);
	if (ft_strlen(little) == 0)
		return ((char *)&big[i]);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

/*#include <string.h>
int	main(void)
{
	char	tab[] = "oh no not the empty string!";
	char	tab2[] = "";
	printf("%s", ft_strnstr(tab, tab2, 0));
	printf("\n%d", strnstr(tab, tab2, 0));
	return (0);
}*/