/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:55:48 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/14 15:23:04 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		while (n--)
			(*(unsigned char *)(dest + n)) = (*(unsigned char *)(src + n));
	}
	return (dest);
}

/*int	main(void)
{
	char dest[] = "abdc";
	char src[] = "zqsa";
	//printf("%s\n", dest);
	ft_memmove(dest, src, 4);
	printf("%s", dest);
	return (0);
}*/