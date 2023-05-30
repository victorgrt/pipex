/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:36:21 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/17 18:49:05 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*boeuf;

	(void) (*del);
	boeuf = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&boeuf, ft_lstnew((*f)(lst->content)));
		lst = lst->next;
	}
	return (boeuf);
}

/*static void	ecrire(void *str)
{
	int	i;
	char	*tab;

	tab = (char *)str;
	i = 0;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
}

int	main(void)
{
	t_list	*tab = ft_lstnew("i am");
	t_list	*tab2 = ft_lstnew("the one");
	t_list	*tab3 = ft_lstnew("who");
	t_list	*tab4 = ft_lstnew("knocks");
	tab->next = tab2;
	tab2->next = tab3;
	tab3->next = tab4;
	ft_lstmap(tab, (void *)ecrire, (void *)ecrire);
	printf("%s\n%s\n%s\n%s\n", (char *)tab->content, (char *)tab2->content,
	(char *)tab3->content, (char *)tab4->content);
	return (0);
}*/