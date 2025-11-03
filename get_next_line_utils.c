/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:43 by david             #+#    #+#             */
/*   Updated: 2025/11/03 20:32:58 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cpy;
	int		i;
	int		total;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	cpy = malloc(total * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j])
		cpy[i++] = s2[j++];
	cpy[i] = '\0';
	return (cpy);
}


int	ft_strchr(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '\n')
			return (0);
		x++;
	}
	return (-1);
}

// int	main(void)
// {
// 	char buffer[] = "vide = ";
// 	char line[] = "je suis l'école 42davida\n vdaivd";
// 	char *result = ft_strncat(buffer,line);
// 	printf("%s", result);
// }