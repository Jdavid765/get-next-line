/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:11 by david             #+#    #+#             */
/*   Updated: 2025/10/27 17:10:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char *line)
{
	int		count; // Compter le nombre de lecture de read 
	int		nb_read; // stocker les valeurs de read ou il c est arreter

	nb_read = -1;
	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (nb_read != 0)
	{
		nb_read = read(fd, line,BUFF_SIZE);
		if (nb_read == -1)
			return (1);
		line[nb_read] = '\0';
		printf("%s\n", line);
		count++;
	}
	printf("%d\n",count);
	close(fd);
	return (0);
}

int	main(void)
{
	int	fd = 0;
	char line[BUFF_SIZE + 1];
	int resultat = get_next_line(fd,line);
	if(resultat == 1)
		printf("Erreur\n");
	else
		printf("Voici le résultat = %d", resultat);
}