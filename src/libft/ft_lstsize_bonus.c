/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:03:51 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/18 13:38:22 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list	*tab1 = ft_lstnew("I");
	t_list	*tab2 = ft_lstnew("have");
	t_list	*tab3 = ft_lstnew("the high ground");
	tab1->next = tab2;
	tab2->next = tab3;

	printf("%d\n", ft_lstsize(tab1));
	return (0);
}*/