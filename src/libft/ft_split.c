/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:16:16 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/18 13:24:40 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checksep(const char s, char c)
{
	if (c == s)
		return (1);
	return (0);
}

static int	wordcount(const char *s, char c)
{
	int	compteur;

	compteur = 0;
	while (*s)
	{
		while (*s && checksep(*s, c))
			s++;
		if (*s)
			compteur++;
		while (*s && !checksep(*s, c))
			s++;
	}
	return (compteur);
}

static int	strlensep(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && !checksep(s[i], c))
		i++;
	return (i);
}

static char	*makeword(const char *s, char c)
{
	char	*word;
	int		i;
	int		len;

	len = strlensep(s, c);
	word = malloc(sizeof(*word) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (*s && !checksep(*s, c))
		word[i++] = *(s++);
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**new;
	int		i;

	new = malloc(sizeof(*new) * (wordcount(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && checksep(*s, c))
			s++;
		if (*s)
		{
			new[i] = makeword(s, c);
			if (!new[i++])
			{
				free(new[i]);
				return (NULL);
			}
		}
		while (*s && !checksep(*s, c))
			s++;
	}
	new[i] = NULL;
	return (new);
}

/*int    main(int ac, char **av)
{
    int    i;
    char    **tab1;

    if (ac != 3)
        return (0);
    tab1 = ft_split(av[1], av[2][0]);
    i = 0;
    while (i < wordcount(av[1], av[2][0]))
    {
        printf("%s \n", tab1[i]);
        free(tab1[i++]);
    }
    free(tab1);
    return (0);
}*/
