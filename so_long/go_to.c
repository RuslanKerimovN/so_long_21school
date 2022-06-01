/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:09:45 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:51:42 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_down(t_data *check, int i, int j)
{
	ft_step();
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50, i * 50 + 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50, i * 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.bird, j * 50, i * 50 + 50);
	g_el.player_x = j;
	g_el.player_y = i + 1;
	if (check->mass_map[i + 1][j] == 'C' && g_el.num_coll > 0)
	{
		g_el.num_coll--;
		check->mass_map[i + 1][j] = '0';
	}
}

void	ft_up(t_data *check, int i, int j)
{
	ft_step();
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50, i * 50 - 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50, i * 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.bird, j * 50, i * 50 - 50);
	g_el.player_x = j;
	g_el.player_y = i - 1;
	if (check->mass_map[i - 1][j] == 'C' && g_el.num_coll > 0)
	{
		g_el.num_coll--;
		check->mass_map[i - 1][j] = '0';
	}
}

void	ft_right(t_data *check, int i, int j)
{
	ft_step();
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50 + 50, i * 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50, i * 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.bird, j * 50 + 50, i * 50);
	g_el.player_x = j + 1;
	g_el.player_y = i;
	if (check->mass_map[i][j + 1] == 'C' && g_el.num_coll > 0)
	{
		g_el.num_coll--;
		check->mass_map[i][j + 1] = '0';
	}
}

void	ft_left(t_data *check, int i, int j)
{
	ft_step();
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50 - 50, i * 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.gaz, j * 50, i * 50);
	mlx_put_image_to_window(g_el.mlx,
		g_el.win, g_el.bird, j * 50 - 50, i * 50);
	g_el.player_x = j - 1;
	g_el.player_y = i;
	if (check->mass_map[i][j - 1] == 'C' && g_el.num_coll > 0)
	{
		g_el.num_coll--;
		check->mass_map[i][j - 1] = '0';
	}
}
