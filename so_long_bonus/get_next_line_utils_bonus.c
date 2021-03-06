/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:34:09 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:55:06 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	size_t	j;
	char	*f;

	f = s;
	i = 0;
	j = 0;
	while (j < n)
	{
		f[i] = 0;
		i++;
		j++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*crazy;

	crazy = (char *)malloc(size * count);
	if (!crazy)
		return (NULL);
	ft_bzero(crazy, size * count);
	return (crazy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' || s[i] == c)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	int		j;
	int		r;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	k = 0;
	j = 0;
	r = ft_strlen(s2);
	i = ft_strlen(s1);
	str = (char *)malloc((i + r + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[k] && k < i)
	{
		str[k] = s1[k];
		k++;
	}
	while (s2[j] && k < (i + r))
		str[k++] = s2[j++];
	str[k] = '\0';
	return (str);
}
