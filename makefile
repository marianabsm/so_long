# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marianamestre <marianamestre@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 11:26:57 by marianamest       #+#    #+#              #
#    Updated: 2024/05/26 16:52:35 by marianamest      ###   ########.fr        #
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

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(MLX_DIR) -I/opt/X11/include -fsanitize=address
LDFLAGS = -L$(MLX_DIR) -lmlx -L/opt/X11/lib -lX11 -lXext -lm -framework OpenGL -framework AppKit -framework CoreFoundation
MLX_DIR = ./minilibx_macos

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all