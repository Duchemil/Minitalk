/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by lduchemi          #+#    #+#             */
/*   Updated: 2024/04/30 14:59:40 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	int		i;
	char	*dest;

	if (!s1)
	{
		dest = malloc(sizeof(char) * 2);
		if (!dest)
			return (NULL);
		dest[0] = s2;
		dest[1] = '\0';
		return (dest);
	}
	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = s2;
	dest[i + 1] = '\0';
	free(s1);
	return (dest);
}
