/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:13:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/13 13:20:53 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*boeuf;

	if (*lst)
	{
		while (*lst)
		{
			boeuf = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = boeuf;
		}
	}
}

/*int	main(void)
{
	t_list	*tab = ft_lstnew("omaewa");
	t_list	*tab2 = ft_lstnew("mou");
	t_list	*tab3 = ft_lstnew("shideiru");
	t_list	*tab4 = ft_lstnew("NANI?!");
	
	tab->next = tab2;
	tab2->next = tab3;
	tab3->next = tab4;
	//printf("%s\n%s\n%s\n%s\n", (char *)(tab)->content, (char *)(tab2)->content,
	//(char *)(tab3)->content, (char *)(tab4)->content);
	printf("%s\n", (char *)tab4->content);
	ft_lstclear(&tab4, (void *)ft_lstdelone);
	//printf("%s\n", (char *)tab4->content);
	printf("%s\n%s\n%s\n", (char *)(tab)->content, (char *)(tab2)->content,
	(char *)(tab3)->content);
	printf("%s\n", (char *)tab4->content);
	return (0);
}*/