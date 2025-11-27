/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celen <celen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:05:56 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/27 14:36:58 by celen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

ssize_t	ft_get_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

ssize_t	ft_get_size_uint(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	ft_putnbr_uint_fd(unsigned int nb, int fd)
{
	if (nb / 10 != 0)
		ft_putnbr_uint_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

ssize_t	ft_get_size_hex(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 16)
	{
		n /= 16;
		size++;
	}
	return (size);
}
