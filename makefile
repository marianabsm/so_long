# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marianamestre <marianamestre@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 11:26:57 by marianamest       #+#    #+#              #
#    Updated: 2024/05/03 11:30:41 by marianamest      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = -I/opt/X11/include -Imlx

SRCS = algorithms/generalsort.c algorithms/sort3.c algorithms/sort5.c \
finders/besties.c finders/values.c \
moves/swap.c moves/push.c moves/rotate.c moves/revrotate.c \
utils/lists/ft_lstadd_back.c utils/lists/ft_lstlast.c utils/lists/ft_lstnew.c utils/lists/ft_lstsize.c \
utils/atol.c utils/checkers.c utils/cost.c utils/free.c utils/ft_split.c utils/putontop.c \
main.c 

OFILES	= $(SRCS:.c=.o)
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
	
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

all: $(NAME)

${NAME} : ${OFILES}	

	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(OFILES) $(MLX_FLAGS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all