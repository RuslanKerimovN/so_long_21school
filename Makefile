# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: botilia <botilia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 14:55:40 by botilia           #+#    #+#              #
#    Updated: 2021/12/24 10:24:44 by botilia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SO_LONG_RUN

SL =		so_long/check_map.c \
			so_long/clear.c \
			so_long/go_to.c \
			so_long/init_picture.c \
			so_long/new_window_and_init.c \
			so_long/check_map2.c \
			so_long/get_next_line.c \
			so_long/get_next_line_utils.c \
			so_long/init_keys.c \
			so_long/libft.c \
			so_long/so_long.c \
			so_long/step_winner_exit.c \

SL_B =		so_long_bonus/bonus_ft_s.c \
			so_long_bonus/clear_bonus.c \
			so_long_bonus/get_next_line_utils_bonus.c \
			so_long_bonus/init_picture_bonus.c \
			so_long_bonus/so_long_bonus.c \
			so_long_bonus/check_map2_bonus.c \
			so_long_bonus/get_next_line_bonus.c \
			so_long_bonus/go_to_bonus.c \
			so_long_bonus/libft_bonus.c \
			so_long_bonus/check_map_bonus.c \
			so_long_bonus/init_keys_bonus.c \
			so_long_bonus/new_window_and_init_bonus.c \
			so_long_bonus/step_winner_exit_bonus.c \

SL_H =		so_long/so_long.h \

SL_H_B = 	so_long_bonus/solong_bonus.h \

MINILIBX = libmlx.dylib

OBJ = $(patsubst %.c,%.o,$(SL))

OBJ_B = $(patsubst %.c,%.o,$(SL_B))

FLAGS = -Wall -Wextra -Werror -L minilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ) $(SL_H)
	@make -C minilibx
	@cp minilibx/$(MINILIBX) .
	cc $(FLAGS) $(SL) -o $(NAME)

bonus : $(OBJ_B) $(SL_H_B)
	@make -C minilibx
	@cp minilibx/$(MINILIBX) .
	cc $(FLAGS) $(SL_B) -o $(NAME)

clean :
	@rm -f $(OBJ) $(OBJ_B)
	@make clean -C minilibx

fclean : clean
	@rm -f $(NAME)
	@rm -f $(MINILIBX)

re : fclean all

.PHONY : all clean fclean re bonus