/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:29 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/11 13:53:36 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p++ = '\0';
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (void *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return (p);
}

char	*ft_strjoin(char *s1, char s2)
{
	int		s1_len;
	int		i;
	char	*str;

	s1_len = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(*s1) * 1);
		if (!s1)
			return (NULL);
		else
			s1[0] = '\0';
	}
	else
		s1_len = ft_strlen(s1);
	str = malloc((s1_len + 2) * sizeof(*str));
	if (!str)
		return (NULL);
	i = -1;
	while (i++ < s1_len - 1)
		str[i] = s1[i];
	str[i] = s2;
	str[i + 1] = '\0';
	free(s1);
	return (str);
}
