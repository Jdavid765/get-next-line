/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:11 by david             #+#    #+#             */
/*   Updated: 2025/11/04 15:46:09 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer, char *line)
{
	int		nb_bytes;
	char	*tmp;

	nb_bytes = 1;
	if (fd < 0 || !buffer || !line)
		return (NULL);
	while (nb_bytes != 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
			return (NULL);
		buffer[nb_bytes] = '\0';
		tmp = ft_strjoin(line,buffer);
		free(line);
		line = tmp;
		nb_bytes = ft_strchr(line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*cpy;
	static int	position;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
		position = 0;
	}
	line = ft_read(fd, buffer, line);
	cpy = ft_strcpy(line, &position);
	return (cpy);
}

int	main(void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	char *resultat1 = get_next_line(fd);
	char *resultat2 = get_next_line(fd);
	char *resultat3 = get_next_line(fd);
	char *resultat4 = get_next_line(fd);
	char *resultat5 = get_next_line(fd);
	printf("%s", resultat1);
	printf("%s", resultat2);
	printf("%s", resultat3);
	printf("%s", resultat4);
	printf("%s", resultat5);
	close(fd);
	return (0);
}