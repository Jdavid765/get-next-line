/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:43 by david             #+#    #+#             */
/*   Updated: 2025/10/30 16:19:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while(*s++)
		count++;
	return(count);
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
	cpy = malloc(total* sizeof(char));
	if(!cpy)
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

// int	main(void)
// {
// 	char s1[] = "Bonjour david je suis ";
// 	char s2[] = "paul";
// 	printf("%s", ft_strjoin(s1, s2));
// }