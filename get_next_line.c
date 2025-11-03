/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:11 by david             #+#    #+#             */
/*   Updated: 2025/11/03 20:34:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_open(int fd)
{
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

char	*ft_read(int fd, char *buffer, char *line)
{
	int		nb_bytes;
	char	*tmp;

	nb_bytes = -1;
	if (fd < 0 || !buffer || !line)
		return (NULL);
	while (nb_bytes != 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
			return (NULL);
		buffer[nb_bytes] = '\0';
		tmp = ft_strjoin(line, buffer);
		free (line);
		line = tmp;
		nb_bytes = ft_strchr(line);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	fd = ft_open(fd);
	line = ft_read(fd, buffer, line);
	close (fd);
	return (line);
}

int	main(void)
{
	int	fd = 1;
	char *resultat = get_next_line(fd);
	resultat = get_next_line(fd);
	resultat = get_next_line(fd);
	printf("%s\n", resultat);
	return (0);
}