/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:31:04 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 17:31:22 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*static void	ftoupper(unsigned int i, char *s)
{
	s[i] = s[i] - 32;
}

int	main(void)
{
	char	tab[] = "oui bonjour";
	printf("%s", ft_striteri(tab, ftoupper));
	return (0);
}*/