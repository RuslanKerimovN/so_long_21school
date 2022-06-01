/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:30:33 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:54:54 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	check_ch3(char c)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (1);
	else if (c == 'C')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'P')
		return (1);
	else if (c == 'F')
		return (1);
	else
		return (0);
}

int	check_ch2(char *mass)
{
	int	z;
	int	y;

	y = 0;
	while (mass[y])
	{
		z = 0;
		z = check_ch3(mass[y]);
		if (z == 0)
			return (0);
		y++;
	}
	return (1);
}

int	check_char(t_data *check)
{
	int	i;
	int	z;

	i = 0;
	while (check->mass_map[i])
	{
		z = 0;
		z = check_ch2(check->mass_map[i]);
		if (z == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_1(t_data *check, int i, int j)
{
	if (check->mass_map[i][j] != '1')
		return (0);
	else
		return (1);
}

int	ft_is_E(t_data *check, int i, int j)
{
	if (check->mass_map[i][j] != 'E' && g_el.num_coll >= 0)
		return (0);
	else if (check->mass_map[i][j] == 'E' && g_el.num_coll == 0)
		return (1);
	else
		return (-1);
}
