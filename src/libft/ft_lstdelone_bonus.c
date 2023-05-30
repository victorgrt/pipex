/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:47:10 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/17 18:24:45 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/*static void	fonctiontest(void *str)
{
	char *tmp = (char *)str;
	int	i = ft_strlen(str);

	while (i != -1)
	{
		tmp[i] = '\0';
		i--;
	}
}*/

/*int	main(void)
{
	t_list	*tab = ft_lstnew("jojo");
	t_list	*tab2;
	t_list	*tab3;

	tab2 = ft_lstnew("alan");
	tab3 = ft_lstnew("Robert");\
	tab->next = tab2;
	tab2->next = tab3;
	char	str[] = "petit test";
	printf("%s\n", str);
	fonctiontest((void *)str);
	printf("%s\n", str);
	printf("%s\n%s\n%s\n%d\n", (char *)tab->content, (char *)tab2->content,
	 (char *)tab3->content, ft_lstsize(tab));
	ft_lstdelone(tab3->content, fonctiontest);
	//printf("%d\n", ft_lstsize(tab));
	printf("%s\n%d\n", (char *)tab3->content, ft_lstsize(tab));
	return (0);
}*/

/*int main (void)
{
    t_list *elem1;
    void    *del;

    del = &fonctiontest;
    elem1 = ft_lstnew("elem1");
    printf ("Avant: %s\n",(char *)elem1->content);
    ft_lstdelone(elem1, del);
    printf ("Apres: %ls\n",(int *)elem1->content);
    return (0);
}*/
