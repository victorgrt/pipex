/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:02:54 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/17 17:56:15 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*boeuf;

	if (*lst)
	{
		boeuf = ft_lstlast(*lst);
		boeuf->next = new;
	}
	else
		*lst = new;
}

/*int	main(void)
{
	t_list	*tab;
	t_list	*tab2;
	t_list	*tab3 = ft_lstnew("ALAN LE KING");
	t_list	*tab4 = ft_lstnew("NATHAN GROS BG");
	tab = ft_lstnew("ZAWARUDOOOOO");
	tab2 = ft_lstnew("JOJOOOOO");
	
	tab->next = tab2;
	tab2->next = tab3;
	ft_lstadd_back(&tab, tab4);
	printf("%s\n", (char *)ft_lstlast(tab)->content);
	return (0);
}*/