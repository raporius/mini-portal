/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:56:24 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:03 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return (current);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*l;

// 	l = ft_lstnew(ft_strdup("test1"));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test2")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test3")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test4")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test5")));
// 	printf("%s\n", (char *)(ft_lstlast(l)->content));
// 	ft_lstclear(&l, free);
// 	return (0);
// }