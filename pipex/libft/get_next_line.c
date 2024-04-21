/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:20:31 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/01/02 15:44:54 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *cup)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(cup, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(cup);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		cup = ft_str_get_join(cup, buffer);
	}
	free(buffer);
	return (cup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cup[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cup[fd] = read_file(fd, cup[fd]);
	if (!cup[fd])
		return (NULL);
	line = copy_line(cup[fd]);
	cup[fd] = new_line(cup[fd]);
	return (line);
}
