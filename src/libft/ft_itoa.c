/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:52 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/17 18:47:25 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennb(long n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	unsigned int	len;
	long int		nbr;
	char			*str;

	nbr = nb;
	len = lennb(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[len - 1] = 48 + (nbr % 10);
		nbr /= 10;
		len--;
	}
	return (str);
}

/*#include <limits.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-623));
	printf("%s\n", ft_itoa(-1234));
	return (0);
}*/