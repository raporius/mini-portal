/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:08:34 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:01 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>

// void	ft_print_lst(t_list *l)
// {
// 	t_list	*current;

// 	current = l;
// 	while (current != NULL)
// 	{
// 		printf("%p:%s->%p\n", current, (char *)current->content, current->next);
// 		current = current->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*l;

// 	l = ft_lstnew(ft_strdup("test1"));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test2")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test3")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test4")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test5")));
// 	ft_print_lst(l);
// 	ft_lstdelone(ft_lstlast(l), free);
// 	ft_print_lst(l);
// 	ft_lstclear(&l, free);
// 	return (0);
// }