/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:17:55 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/07 12:44:47 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static ssize_t	ft_flag_u(unsigned int i, int fd)
{
	ft_putnbr_uint_fd(i, fd);
	return (ft_get_size_uint(i));
}

static ssize_t	ft_printf_var(va_list ap, const char id, int fd)
{
	ssize_t	len;

	len = -1;
	if (id == 'c')
		len = ft_flag_c(va_arg(ap, int), fd);
	else if (id == 's')
		len = ft_flag_s(va_arg(ap, char *), fd);
	else if (id == 'p')
		len = ft_flag_p(va_arg(ap, void *), fd);
	else if (id == 'd' || id == 'i')
		len = ft_flag_d_i(va_arg(ap, int), fd);
	else if (id == 'u')
		len = ft_flag_u(va_arg(ap, unsigned int), fd);
	else if (id == 'x')
		len = ft_flag_x(va_arg(ap, int), 'x', fd);
	else if (id == 'X')
		len = ft_flag_x(va_arg(ap, int), 'X', fd);
	else if (id == '%')
	{
		ft_putchar_fd('%', 1);
		len = 1;
	}
	return (len);
}

static int	main_ft_print(const char *s, va_list ap)
{
	size_t	i;
	size_t	var_index;
	size_t	percent_count;

	i = 0;
	var_index = 0;
	percent_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
		if (s[i] == '%')
		{
			percent_count++;
			var_index += ft_printf_var(ap, s[i + 1], 1);
			i += 2;
		}
	}
	return (var_index + i - 2 * percent_count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		ret;

	if (s == NULL)
		return (-1);
	va_start(ap, s);
	ret = main_ft_print(s, ap);
	va_end(ap);
	return (ret);
}
