/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:54:54 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:55:20 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	int		j;

	j = 0;
	i = ft_strlen(s1);
	s2 = (char *)malloc(i + 1 * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[j] != '\0')
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	fnsize(int n)
{
	int	sizemol;

	if (n > 0)
		sizemol = 0;
	else
		sizemol = 1;
	while (n)
	{
		n /= 10;
		sizemol++;
	}
	return (sizemol);
}

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*str;

	i = fnsize(n);
	j = n;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (j < 0)
	{
		j = j * (-1);
		str[0] = '-';
	}
	if (j == 0)
		str[0] = '0';
	str[i] = '\0';
	while (j)
	{
		str[i - 1] = ((j % 10) + 48);
		j /= 10;
		i--;
	}
	return (str);
}
