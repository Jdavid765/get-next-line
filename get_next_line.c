/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:11 by david             #+#    #+#             */
/*   Updated: 2025/10/29 19:24:42 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_open(int fd)
{
	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
		return (NULL);
	return (fd);
}

char	ft_read(int n)
{
	int		nb_read;
	int		filedescriptor;

	nb_read = -1;
	while (nb_read != '\n')
	{
		nb_read = read(fd, line, BUFFER_SIZE);
		if(nb_read == -1)
			return (NULL);
		line[nb_read] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];

	line = ft_read(fd);
	close(fd);
	return (line);
}

int	main(void)
{
	int	fd = 0;
	char *resultat = get_next_line(fd);
	if(resultat == NULL)
		printf("Erreur\n");
	else
		printf("%s", resultat);
}