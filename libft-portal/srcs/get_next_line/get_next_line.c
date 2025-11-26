/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:39:40 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/29 09:44:29 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*buffer_transfer(char *buffer_to_fill, char *buffer)
{
	char	*tmp;

	if (buffer_to_fill == NULL)
		buffer_to_fill = ft_strdup("");
	if (buffer_to_fill == NULL)
		return (NULL);
	tmp = buffer_to_fill;
	buffer_to_fill = ft_strjoin(tmp, buffer);
	free(tmp);
	return (buffer_to_fill);
}

char	*fill_buffer(int fd, char *buffer_to_fill)
{
	char	*buffer;
	ssize_t	size_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	size_read = 1;
	while (size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read <= 0)
		{
			if (size_read == -1 && buffer_to_fill != NULL)
				free(buffer_to_fill);
			break ;
		}
		buffer[size_read] = '\0';
		buffer_to_fill = buffer_transfer(buffer_to_fill, buffer);
		if (buffer_to_fill == NULL || ft_strchr(buffer_to_fill, '\n'))
			break ;
	}
	free(buffer);
	return (buffer_to_fill);
}

char	*separate_buffer(char *static_buffer, char *buffer_to_fill)
{
	char	*ret;
	int		len;
	int		j;

	len = 0;
	j = 0;
	while (buffer_to_fill[len] != '\0' && buffer_to_fill[len] != '\n')
		len++;
	ret = ft_substr(buffer_to_fill, 0, len + 1);
	if (ret != NULL && buffer_to_fill[len] != '\0')
	{
		len++;
		while (buffer_to_fill[len + j] != '\0')
		{
			static_buffer[j] = buffer_to_fill[len + j];
			j++;
		}
		if (j != 0)
			static_buffer[j] = '\0';
	}
	free(buffer_to_fill);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	static_buffer[BUFFER_SIZE + 1] = "\0";
	char		*buffer_to_fill;
	char		*ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_memset(static_buffer, 0, BUFFER_SIZE + 1);
		return (NULL);
	}
	buffer_to_fill = NULL;
	if (static_buffer[0] != '\0')
	{
		buffer_to_fill = ft_strdup(static_buffer);
		if (buffer_to_fill == NULL)
			return (NULL);
	}
	ft_memset(static_buffer, 0, BUFFER_SIZE + 1);
	if (buffer_to_fill == NULL || !ft_strchr(buffer_to_fill, '\n'))
	{
		buffer_to_fill = fill_buffer(fd, buffer_to_fill);
		if (buffer_to_fill == NULL)
			return (NULL);
	}
	ret = separate_buffer(static_buffer, buffer_to_fill);
	return (ret);
}
