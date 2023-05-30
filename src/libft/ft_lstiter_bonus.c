/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:32:07 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/17 16:48:06 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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
	t_list	*tab = ft_lstnew("Pas besoin ");
	t_list	*tab2 = ft_lstnew("du pear ");
	t_list	*tab3 = ft_lstnew("programming ");
	t_list	*tab4 = ft_lstnew("pour cette ");
	t_list	*tab5 = ft_lstnew("fonction!");
	tab->next = tab2;
	tab2->next = tab3;
	tab3->next = tab4;
	tab4->next = tab5;
	ft_lstiter(tab, (void *)ecrire);
	//remplacement(tab2);
	//printf("%s", (char *)tab2->content);
	//printf("\n%s\n%s\n%s\n%s\n%s\n", (char *)tab->content,(char *)tab2->content,
	//(char *)tab3->content,(char *)tab4->content,(char *)tab5->content);
	return (0);
}*/