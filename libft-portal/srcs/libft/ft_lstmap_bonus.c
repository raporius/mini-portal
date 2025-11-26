/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:33:39 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:04 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_elt;
	void	*new_content;

	current = lst;
	new_list = NULL;
	while (current != NULL)
	{
		new_content = f(current->content);
		new_elt = ft_lstnew(new_content);
		if (new_elt == NULL)
			del(new_content);
		ft_lstadd_back(&new_list, new_elt);
		current = current->next;
	}
	return (new_list);
}

// #include <stdio.h>

// void	ft_strtoupper(char *t)
// {
// 	int	i;

// 	i = 0;
// 	while (t[i] != '\0')
// 	{
// 		t[i] = ft_toupper(t[i]);
// 		i++;
// 	}
// }

// void	*ft_map_test(void *t)
// {
// 	void	*new;

// 	new = ft_strdup(t);
// 	ft_strtoupper((char *)new);
// 	return (new);
// }

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
// 	t_list	*l2;

// 	l = ft_lstnew(ft_strdup("test1"));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test2")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test3")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test4")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test5")));
// 	ft_print_lst(l);
// 	printf("------------------\n");
// 	l2 = ft_lstmap(l, ft_map_test, free);
// 	ft_print_lst(l2);
// 	ft_lstclear(&l, free);
// 	ft_lstclear(&l2, free);
// 	return (0);
// }
