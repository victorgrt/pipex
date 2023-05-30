/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:46:41 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/17 17:57:25 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	t_list	*tab;
	t_list	*tab2;
	t_list	*tab3 = ft_lstnew("ALAN LE KING");
	tab = ft_lstnew("ZAWARUDOOOOO");
	tab2 = ft_lstnew("JOJOOOOO");
	
	tab->next = tab2;
	tab2->next = tab3;
	printf("%s\n", (char *)ft_lstlast(tab)->content);
	return (0);
}*/