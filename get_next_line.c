/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:11 by david             #+#    #+#             */
/*   Updated: 2025/11/04 18:36:10 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer, char *line)
{
	int			nb_bytes;
	char		*tmp;

	nb_bytes = 1;
	if (fd < 0 || !buffer || !line)
		return (NULL);
	while ((nb_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (nb_bytes == -1)
			return (NULL);
		buffer[nb_bytes] = '\0';
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
		if (line == NULL)
			return (NULL);
		if (ft_strchr(line) > 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*cpy;
	static int	position;

	printf("%s", line);
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
	if (line == NULL)
		return (NULL);
	free(buffer);
	cpy = ft_strcpy(line, &position);
	return (line);
}

int	main(void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	int count = 0;
	// while (count < 10)
	// {
	// 	char *result = get_next_line(fd);
	// 	printf("%s", result);
	// 	free (result);
	// 	count++;
	// }
	char *resultat = get_next_line(fd);
	printf("--%s", resultat);
	char *resultat1 = get_next_line(fd);
	printf("--%s", resultat1);
	close(fd);
	return (0);
}