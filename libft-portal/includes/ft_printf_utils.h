/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:07:27 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/07 12:46:28 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

ssize_t	ft_flag_c(char c, int fd);
ssize_t	ft_flag_s(char *s, int fd);
ssize_t	ft_flag_p(void *p, int fd);
ssize_t	ft_get_size(int n);
ssize_t	ft_flag_d_i(int i, int fd);
ssize_t	ft_get_size_uint(unsigned int n);
void	ft_putnbr_uint_fd(unsigned int nb, int fd);
void	ft_flag_x_rec(unsigned int nb, int fd, char *charset);
ssize_t	ft_get_size_hex(unsigned int n);
ssize_t	ft_flag_x(int n, char caps, int fd);

#endif
