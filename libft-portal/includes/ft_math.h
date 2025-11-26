/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:00:20 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/26 14:38:54 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

/**
 * @brief calculate the abs of nb
 * @param int nb
 * @return abs of nb
 * 
 *  int max if nb is int min
 */
int		ft_int_abs(int nb);

/**
 * @brief calculate the abs of nb
 * @param long nb
 * @return abs of nb
 * 
 *  long max if nb is long min
 */
long	ft_long_abs(long nb);

/**
 * @brief calculate the power of nb by n
 * @param int nb
 * @param int power
 * @return the power of nb by power
 * 
 *  int max if nb if the result is a overflow
 */
int		ft_power_int(int nb, int power);

/**
 * @brief calculate the power of nb by n
 * @param long nb
 * @param long power
 * @return the power of nb by power
 * 
 *  long max if nb if the result is a overflow
 */
long	ft_power_long(long nb, int power);

/**
 * @brief calculate if nb is a prime number
 * @param int nb
 * @return boolean
 */
int		ft_int_is_prime(int nb);

/**
 * @brief calculate if nb is a prime number
 * @param long nb
 * @return boolean
 */
long	ft_long_is_prime(long nb);

/**
 * @brief compare a to b
 * @param int a
 * @param int b
 * @return the biggest value
 * 
 * a if the numbers are equal
 */
int		max_int(int a, int b);

/**
 * @brief compare a to b
 * @param long a
 * @param long b
 * @return the biggest value
 * 
 * a if the numbers are equal
 */
long	max_long(long a, long b);

/**
 * @brief compare a to b
 * @param int a
 * @param int b
 * @return the lowest value
 * 
 * a if the numbers are equal
 */
int		min_int(int a, int b);

/**
 * @brief compare a to b
 * @param long a
 * @param long b
 * @return the lowest value
 * 
 * a if the numbers are equal
 */
long	min_long(long a, long b);

/**
 * @brief calculate the fibonacci nbr at index
 * 
 * WARNING CAN STACK OVERFLOW USE A YOU OWN RISK
 * @param int index
 * @return the fibanacci nbr at index
 */
int		ft_fibonacci(int index);

/**
 * @brief calculate the factoriel of nb
 * @param int nb
 * @return the result of !nb
 */
int		ft_int_factorielle(int nb);

/**
 * @brief calculate the factoriel of nb
 * @param long nb
 * @return the result of !nb
 */
long	ft_long_factorielle(long nb);

#endif //ft_math.h
