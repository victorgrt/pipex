/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:16:51 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/13 13:20:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		deb;
	int		fin;

	deb = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	fin = ft_strlen(s1);
	while (s1[deb] && ft_isset(s1[deb], set))
		deb++;
	while (fin > deb && ft_isset(s1[fin - 1], set))
		fin--;
	str = (char *)malloc(sizeof(char) * (fin - deb + 1));
	if (!str)
		return (NULL);
	while (deb < fin)
	{
		str[i++] = s1[deb++];
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char tab[] = "!! bonjour !! au revoir !!";
	char set[] = "!!";
	char	*a = ft_strtrim(tab, set);
	printf("%s\n", a);
	free(a);
	return (0);
}*/