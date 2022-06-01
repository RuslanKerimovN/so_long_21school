/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:29:58 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:54:46 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	ft_hunter(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	g_el.hunter = mlx_xpm_file_to_image(g_el.mlx, g_el.hunter_img,
			&g_el.len, &g_el.heig);
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[i][j] == 'F')
				mlx_put_image_to_window(g_el.mlx, g_el.win,
					g_el.hunter, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_hunter2(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	g_el.hunter2 = mlx_xpm_file_to_image(g_el.mlx, g_el.hunter2_img,
			&g_el.len, &g_el.heig);
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[i][j] == 'F')
				mlx_put_image_to_window(g_el.mlx, g_el.win,
					g_el.hunter2, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_f_gaz(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[i][j] == 'F')
				mlx_put_image_to_window(g_el.mlx, g_el.win,
					g_el.gaz, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

int	animation(t_data *check)
{
	g_el.time++;
	if (g_el.time == 4000 && g_el.per_check == 0)
	{
		ft_f_gaz(check);
		ft_hunter2(check);
	}
	else if (g_el.time == 8000 && g_el.per_check == 0)
	{
		ft_f_gaz(check);
		ft_hunter(check);
		g_el.time = 0;
	}
	if (g_el.per_check != 0)
		mlx_xpm_file_to_image(g_el.mlx, g_el.gaz_img,
			&g_el.len, &g_el.heig);
	return (0);
}

void	ft_loser(t_data *check)
{
	int	i;
	int	j;

	ft_step();
	ft_back(check);
	i = check->height / 2 * 50;
	j = check->lenght / 2 * 50;
	mlx_put_image_to_window(g_el.mlx, g_el.win, g_el.hunter, j, i);
	mlx_string_put(g_el.mlx, g_el.win,
		j - 40, i + 80, 0xFFFFFF, "YOU ARE LOSER");
}
