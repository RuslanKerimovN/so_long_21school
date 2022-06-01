/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:37:02 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:51:48 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_back(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	g_el.gaz = mlx_xpm_file_to_image(g_el.mlx, g_el.gaz_img,
			&g_el.len, &g_el.heig);
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			mlx_put_image_to_window(g_el.mlx, g_el.win,
				g_el.gaz, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_wall(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	g_el.tree = mlx_xpm_file_to_image(g_el.mlx, g_el.tree_img,
			&g_el.len, &g_el.heig);
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[i][j] == '1')
				mlx_put_image_to_window(g_el.mlx, g_el.win,
					g_el.tree, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_coll(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	g_el.warm = mlx_xpm_file_to_image(g_el.mlx,
			g_el.warm_img, &g_el.len, &g_el.heig);
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[i][j] == 'C')
				mlx_put_image_to_window(g_el.mlx, g_el.win,
					g_el.warm, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_pers(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	g_el.bird = mlx_xpm_file_to_image(g_el.mlx,
			g_el.bird_img, &g_el.len, &g_el.heig);
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[i][j] == 'P')
			{
				mlx_put_image_to_window(g_el.mlx,
					g_el.win, g_el.bird, j * 50, i * 50);
				g_el.player_x = j;
				g_el.player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_exit(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	g_el.exet = mlx_xpm_file_to_image(g_el.mlx,
			g_el.exit_img, &g_el.len, &g_el.heig);
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			if (check->mass_map[i][j] == 'E')
				mlx_put_image_to_window(g_el.mlx,
					g_el.win, g_el.exet, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
