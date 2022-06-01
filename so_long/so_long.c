/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:30:32 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 17:51:57 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fine_height(char *rd_map)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(rd_map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	fine_lenght(char *rd_map)
{
	int		lenght;
	int		fd;
	char	*line;

	fd = open(rd_map, O_RDONLY);
	line = get_next_line(fd);
	lenght = ft_strlen(line);
	free(line);
	close(fd);
	return (lenght);
}

char	**find_mass(char *rd_map, t_data *check)
{
	int		i;
	int		fd;
	char	**mass_map;
	char	*line;

	i = 0;
	mass_map = (char **)malloc(sizeof(char *) * (check->height + 1));
	if (!mass_map)
		return (NULL);
	fd = open(rd_map, O_RDONLY);
	while (i < check->height)
	{
		line = get_next_line(fd);
		mass_map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	mass_map[i] = NULL;
	close(fd);
	return (mass_map);
}

int	main(int argc, char **argv)
{
	t_data	*check;

	if (argc == 2)
	{
		check = malloc(sizeof(t_data *));
		if (!check)
		{
			ft_putstr("SORRY , ERROR OF MEMORY ALLOCATE\n");
			return (0);
		}
		check->height = fine_height(argv[1]);
		check->lenght = fine_lenght(argv[1]);
		check->mass_map = find_mass(argv[1], check);
		if (!check_error(check))
		{
			ft_putstr("SORRY YOUR MAP INVALID\n");
			ft_clear_mass(check);
			free(check);
			return (0);
		}
		new_window(check);
		ft_clear_mass_chars(check);
		free(check);
	}
	return (0);
}
