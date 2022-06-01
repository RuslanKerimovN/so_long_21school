/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window_and_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:57:32 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:51:54 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_image(void)
{
	g_el.per_check = 0;
	g_el.coll = 0;
	g_el.exit = 0;
	g_el.pers = 0;
	g_el.step = 0;
	g_el.gaz_img = "./sprite/gazon.xpm";
	g_el.tree_img = "./sprite/tree.xpm";
	g_el.warm_img = "./sprite/warm.xpm";
	g_el.bird_img = "./sprite/bird.xpm";
	g_el.exit_img = "./sprite/exit.xpm";
}

void	new_window(t_data *check)
{
	g_el.mlx = mlx_init();
	g_el.win = mlx_new_window(g_el.mlx, check->lenght * 50,
			check->height * 50, "so_long");
	ft_init_image();
	ft_back(check);
	ft_wall(check);
	ft_coll(check);
	ft_pers(check);
	ft_exit(check);
	mlx_hook (g_el.win, 2, 0, ft_key, check);
	mlx_hook (g_el.win, 17, 0, ft_key_exit, check);
	mlx_loop(g_el.mlx);
}
