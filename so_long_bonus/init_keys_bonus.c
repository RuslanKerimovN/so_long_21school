/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:33:13 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:55:12 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	ft_key_A(t_data *check, int j, int i)
{
	if (ft_is_1(check, i, j - 1) == 0 && ft_is_E(check, i, j - 1) == 0)
		ft_left(check, i, j);
	else if (ft_is_1(check, i, j - 1) == 0 && ft_is_E(check, i, j - 1) == 1)
	{
		ft_step();
		ft_back(check);
		ft_winner(check);
		g_el.per_check++;
	}
}

void	ft_key_D(t_data *check, int j, int i)
{
	if (ft_is_1(check, i, j + 1) == 0 && ft_is_E(check, i, j + 1) == 0)
		ft_right(check, i, j);
	else if (ft_is_1(check, i, j + 1) == 0 && ft_is_E(check, i, j + 1) == 1)
	{
		ft_step();
		ft_back(check);
		ft_winner(check);
		g_el.per_check++;
	}
}

void	ft_key_W(t_data *check, int j, int i)
{
	if (ft_is_1(check, i - 1, j) == 0 && ft_is_E(check, i - 1, j) == 0)
		ft_up(check, i, j);
	else if (ft_is_1(check, i - 1, j) == 0 && ft_is_E(check, i - 1, j) == 1)
	{
		ft_step();
		ft_back(check);
		ft_winner(check);
		g_el.per_check++;
	}
}

void	ft_key_S(t_data *check, int j, int i)
{
	if (ft_is_1(check, i + 1, j) == 0 && ft_is_E(check, i + 1, j) == 0)
		ft_down(check, i, j);
	else if (ft_is_1(check, i + 1, j) == 0 && ft_is_E(check, i + 1, j) == 1)
	{
		ft_step();
		ft_back(check);
		ft_winner(check);
		g_el.per_check++;
	}
}

int	ft_key(int keycode, t_data *check)
{
	int	i;
	int	j;

	i = g_el.player_y;
	j = g_el.player_x;
	if (keycode == 53)
		exit (0);
	if (keycode == 0 && g_el.per_check == 0)
		ft_key_A(check, j, i);
	if (keycode == 2 && g_el.per_check == 0)
		ft_key_D(check, j, i);
	if (keycode == 13 && g_el.per_check == 0)
		ft_key_W(check, j, i);
	if (keycode == 1 && g_el.per_check == 0)
		ft_key_S(check, j, i);
	return (0);
}
