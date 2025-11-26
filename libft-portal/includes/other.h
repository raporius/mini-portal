/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:39:18 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/24 15:41:44 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

# include "libft.h"

/**
 * @brief convert a str in long
 * @param str
 * @return number converted
 */
long	ft_atol(const char *str);

/**
 * @brief convert a str in long
 * @param str, nbr address
 * @return index of the end of number
 */
int		ft_atol_p(const char *str, long *nbr);

/**
 * @brief swap the address of a to b
 * 
 * swap the address of b to a
 * @param int address a, address b
 */
void	swap_int(int *a, int *b);

/**
 * @brief swap the address of a to b
 * 
 * swap the address of b to a
 * @param long address a, address b
 */
void	swap_long(long *a, long *b);

/**
 * @brief swap the address of a to b
 * 
 * swap the address of b to a
 * @param str address a, address b
 */
void	swap_str(char **a, char **b);

#endif //other.h