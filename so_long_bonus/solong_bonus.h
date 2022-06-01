/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:03:02 by botilia           #+#    #+#             */
/*   Updated: 2021/12/23 18:21:49 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "mlx.h"
# include "get_next_line_bonus.h"

typedef struct s_data
{
	char	**mass_map;
	int		height;
	int		lenght;

}t_data;

typedef struct s_elems
{
	int		coll;
	int		pers;
	int		exit;
	int		frag;

	void	*mlx;
	void	*win;
	int		len;
	int		heig;

	int		player_x;
	int		player_y;
	int		num_coll;
	int		per_check;
	int		step;
	int		time;

	char	*gaz_img;
	char	*tree_img;
	char	*warm_img;
	char	*bird_img;
	char	*exit_img;
	char	*hunter_img;
	char	*hunter2_img;

	void	*gaz;
	void	*tree;
	void	*warm;
	void	*bird;
	void	*exet;
	void	*hunter;
	void	*hunter2;

}t_elems;

t_elems	g_el;

int		fine_height(char *rd_map);
int		fine_lenght(char *rd_map);
char	**find_mass(char *rd_map, t_data *check);

void	new_window(t_data *check);
void	ft_init_image(void);

int		check_lines_and_rect(t_data *check);
int		check_wall(t_data *check);
int		check_elems(t_data *check);
int		check_char(t_data *check);
int		check_ch2(char *mass);
int		check_ch3(char c);
int		check_error(t_data *check);

void	ft_back(t_data *check);
void	ft_wall(t_data *check);
void	ft_coll(t_data *check);
void	ft_pers(t_data *check);
void	ft_exit(t_data *check);

void	ft_key_A(t_data *check, int j, int i);
void	ft_key_D(t_data *check, int j, int i);
void	ft_key_W(t_data *check, int j, int i);
void	ft_key_S(t_data *check, int j, int i);
int		ft_key(int keycode, t_data *check);
int		ft_is_1(t_data *check, int i, int j);
int		ft_is_E(t_data *check, int i, int j);

void	ft_left(t_data *check, int i, int j);
void	ft_right(t_data *check, int i, int j);
void	ft_down(t_data *check, int i, int j);
void	ft_up(t_data *check, int i, int j);

void	ft_step(void);
void	ft_winner(t_data *check);
int		ft_key_exit(t_data *data);

char	*ft_strdup(const char *s1);
void	ft_putstr(char *s);
int		fnsize(int n);
char	*ft_itoa(int n);

void	ft_clear_mass(t_data *check);
void	ft_clear_mass_chars(t_data *check);

void	ft_hunter(t_data *check);
void	ft_hunter2(t_data *check);
void	ft_f_gaz(t_data *check);
void	ft_loser(t_data *check);
int		animation(t_data *check);

#endif