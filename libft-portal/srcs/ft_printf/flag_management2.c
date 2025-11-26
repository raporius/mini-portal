/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:59:08 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/27 18:39:56 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_flag_x_rec(unsigned int nb, int fd, char *charset)
{
	if (nb / 16 != 0)
		ft_flag_x_rec(nb / 16, fd, charset);
	ft_putchar_fd(charset[nb % 16], fd);
}

ssize_t	ft_flag_x(int n, char caps, int fd)
{
	char	*charset;

	if (caps == 'X')
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	ft_flag_x_rec(n, fd, charset);
	return (ft_get_size_hex(n));
}
