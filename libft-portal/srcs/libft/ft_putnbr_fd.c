/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:18:03 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/14 17:01:02 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_rec(long nb, int fd)
{
	if (nb / 10 != 0)
		putnbr_rec(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	putnbr_rec(nb, fd);
}

// int	main(void)
// {
// 	ft_putnbr_fd(2147483647, 1);
// 	write(1, "|2147483647\n", 12);
// 	ft_putnbr_fd(-2147483648, 1);
// 	write("|-2147483648\n", 13);
// 	ft_putnbr_fd(564515, 1);
// 	write("|564515\n", 8);
// 	ft_putnbr_fd(-346181, 1);
// 	write("|-346181\n", 9);
// 	ft_putnbr_fd(0, 1);
// 	write("|0\n", 3);
// 	ft_putnbr_fd(-1, 1);
// 	write("|-1\n", 4);
// 	ft_putnbr_fd(1, 1);
// 	write("|1\n", 3);
// 	ft_putnbr_fd(-31, 1);
// 	write("|-31\n", 5);
// }
