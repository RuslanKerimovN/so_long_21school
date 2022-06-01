/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_winner_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:01:02 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:52:02 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_step(void)
{
	char	*step;

	ft_putstr("number of step = ");
	g_el.step++;
	step = ft_itoa(g_el.step);
	ft_putstr(step);
	write(1, "\n", 1);
	free(step);
}

void	ft_winner(t_data *check)
{
	int	i;
	int	j;

	i = check->height / 2 * 50;
	j = check->lenght / 2 * 50;
	mlx_put_image_to_window(g_el.mlx, g_el.win, g_el.exet, j, i);
	mlx_string_put(g_el.mlx, g_el.win,
		j - 40, i + 80, 0xFFC0CB, "YOU ARE WINNER");
}

int	ft_key_exit(t_data *check)
{
	(void)check;
	exit (0);
}
