# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 11:26:57 by marianamest       #+#    #+#              #
#    Updated: 2024/05/26 19:01:09 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h

SRCS = GNL/get_next_line.c GNL/get_next_line_utils.c \
main.c \
utils/floodfill.c utils/frees.c utils/random_utils.c utils/itoa.c \
map/element_checks.c map/map_checks.c map/inits.c map/wall_checks.c \
mlx/mlx_start.c mlx/images.c mlx/actions.c mlx/loops.c \

# !!!! LEMBRA DE MUDAR O MLX DE MAC-OS PARA LINUX ANTES DA ENTREGA !!!
# FORA E DENTRO DO MAKEFILE!!!!!
OBJS = $(SRCS:.c=.o)
MLX = minilibx-linux/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LDFLAGS = -lm -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o   $(NAME) $(MLX) $(LDFLAGS) -g

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all