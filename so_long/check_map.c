/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:50:02 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:50:11 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_lines_and_rect(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	if (check->lenght == check->height
		|| check->height < 3 || check->lenght < 3)
		return (0);
	while (check->mass_map[i])
	{
		j = 0;
		j = ft_strlen(check->mass_map[i]);
		if (j != check->lenght)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[0][j] != '1' ||
				check->mass_map[check->height - 1][j] != '1')
				return (0);
			if (check->mass_map[i][0] != '1' ||
				check->mass_map[i][check->lenght - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_elems(t_data *check)
{
	int	i;
	int	y;

	i = 0;
	while (check->mass_map[i])
	{
		y = 0;
		while (check->mass_map[i][y])
		{
			if (check->mass_map[i][y] == 'C')
				g_el.coll++;
			else if (check->mass_map[i][y] == 'E')
				g_el.exit++;
			else if (check->mass_map[i][y] == 'P')
				g_el.pers++;
			y++;
		}
		i++;
	}
	if (g_el.coll != 1 || g_el.pers != 1 || g_el.exit == 0)
		return (0);
	g_el.num_coll = g_el.coll;
	return (1);
}

int	check_error(t_data *check)
{
	int	lines_rect;
	int	wall;
	int	elems;
	int	chars;
	int	x;

	lines_rect = check_lines_and_rect(check);
	wall = check_wall(check);
	elems = check_elems(check);
	chars = check_char(check);
	x = lines_rect + wall + elems + chars;
	if (x < 4)
		return (0);
	return (1);
}
