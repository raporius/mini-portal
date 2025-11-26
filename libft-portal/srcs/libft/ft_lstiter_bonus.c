/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:31:28 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:02 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

// #include <stdio.h>

// void	ft_iter_test(void *t)
// {
// 	int	i;

// 	i = 0;
// 	while (((char *)t)[i] != '\0')
// 	{
// 		((char *)t)[i] = ft_toupper(((char *)t)[i]);
// 		i++;
// 	}
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

// 	l = ft_lstnew(ft_strdup("test1"));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test2")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test3")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test4")));
// 	ft_lstadd_back(&l, ft_lstnew(ft_strdup("test5")));
// 	ft_print_lst(l);
// 	printf("-----------\n");
// 	ft_lstiter(l, ft_iter_test);
// 	ft_print_lst(l);
// 	ft_lstclear(&l, free);
// 	return (0);
// }