/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:41:35 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/27 18:40:20 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

ssize_t	ft_flag_c(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

ssize_t	ft_flag_s(char *s, int fd)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}

static ssize_t	ft_flag_p_main(void *p, int fd)
{
	unsigned long long	addr_to_nbr;
	char				to_write;
	int					count;

	count = 1;
	addr_to_nbr = (unsigned long long) p;
	to_write = '0' + addr_to_nbr % 16;
	if (to_write > '9')
		to_write = to_write + 39;
	if (addr_to_nbr / 16)
		count += ft_flag_p_main((void *)(addr_to_nbr / 16), fd);
	ft_putchar_fd(to_write, fd);
	return (count);
}

ssize_t	ft_flag_p(void *p, int fd)
{
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	return (2 + ft_flag_p_main(p, fd));
}

ssize_t	ft_flag_d_i(int i, int fd)
{
	ft_putnbr_fd(i, fd);
	return (ft_get_size(i));
}
