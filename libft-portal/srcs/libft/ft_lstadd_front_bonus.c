/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:48:44 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 11:49:04 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*old_first;

	old_first = *lst;
	*lst = new;
	(*lst)->next = old_first;
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
// 	ft_lstadd_front(&l, ft_lstnew(ft_strdup("test2")));
// 	ft_lstadd_front(&l, ft_lstnew(ft_strdup("test3")));
// 	ft_lstadd_front(&l, ft_lstnew(ft_strdup("test4")));
// 	ft_lstadd_front(&l, ft_lstnew(ft_strdup("test5")));
// 	ft_print_lst(l);
// 	ft_lstclear(&l, free);
// 	return (0);
// }