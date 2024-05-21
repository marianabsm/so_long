# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 11:26:57 by marianamest       #+#    #+#              #
#    Updated: 2024/05/21 14:30:00 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h

SRCS = GNL/get_next_line.c GNL/get_next_line_utils.c \
main.c \
utils/floodfill.c utils/frees.c utils/random_utils.c \
map/element_checks.c map/map_checks.c map/inits.c map/wall_checks.c \


CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

OFILES	= $(SRCS:.c=.o)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME) -g
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
