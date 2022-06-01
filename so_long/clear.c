/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:39:51 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:50:21 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_mass(t_data *check)
{
	int	i;

	i = 0;
	while (check->mass_map[i])
	{
		free(check->mass_map[i]);
		i++;
	}
	free(check->mass_map);
}

void	ft_clear_mass_chars(t_data *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check->mass_map[i])
	{
		j = 0;
		while (check->mass_map[i][j])
		{
			free(&check->mass_map[i][j]);
			j++;
		}
		i++;
	}
}
