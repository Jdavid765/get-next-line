/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:11 by david             #+#    #+#             */
/*   Updated: 2025/10/30 16:49:26 by david            ###   ########.fr       */
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
		if (!tmp)
			return (NULL);
		free(line);
		line = tmp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	fd = ft_open(fd);
	line = ft_read(fd, buffer, line);
	close (fd);
	return (line);
}

int	main(void)
{
	int	fd = 1;
	char *resultat = get_next_line(fd);
	if(resultat == NULL)
		printf("Erreur\n");
	else
		printf("%s\n", resultat);
	return (0);
}