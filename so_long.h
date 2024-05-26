/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:36:09 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 16:14:07 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_ROWS 50
# define MAX_COLUMNS 50

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ESC 53

# include "GNL/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}			t_mlx;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_map
{
	char	**map;
	char	*str_of_actions;
	int		num_of_actions;
	int		start_pos[2];
	int		exit_pos[2];
	int		found_exit;
	int		found_all_collectibles;
	int		rows_in_map;
	int		columns_in_map;
	int		map_fd;
	int		scissors;
	int		valid_exit;
	int		collectibles;
	int		player_position;
	int		empty_space;
	int		running;
	t_img	*img;
	t_mlx	*mlx;
}			t_map;

/* map stuff */
int			map_file_checker(char *str);
void		map_init(t_map *content, int i, char **str);
int			valid_top_wall(t_map *content);
int			valid_middle_walls(t_map *content);
int			valid_bottom_wall(t_map *content);
int			is_map_rectangular(t_map *content);
int			valid_walls(t_map *content);
int			map_layout(t_map *content, char **argv);
void		data_init(t_map *content);

/* element checks */
int			valid_exit(t_map *content);
int			collectible(t_map *content);
int			empty_space(t_map *content);
int			player_position(t_map *content);
int			valid_elements(t_map *content);

/* frees */
void		free_map(t_map *content);
void		free_mlx(t_map *content);

/* floodfill */
int			is_valid_cell(int x, int y, int rows, int cols);
void		flood_fill_recursive(t_map *content, int x, int y,
				int visited[][MAX_COLUMNS]);
int			flood_fill(t_map *content);
void		where_is_player(t_map *content);
void		where_is_exit(t_map *content);

/* itoa */
char		*ft_itoa(int nbr);
int			get_len(int nbr);
int			ft_neg(int nbr);

/* utils */
int			slen(const char *s);
void		line_break_eraser(t_map *content);
int			lines_read_counter(t_map *content);

/* mlx */
void		mlx_start(t_map *content);
void		image_to_window(t_map *content, int x, int y);
void		images_to_map1(t_map *content, char element, int x, int y);
void		images_to_map2(t_map *content, char element);
void		scissors_loop(t_map *content);
int			find_element(t_map *content);
int			actions(int key_code, t_map *content);
int			actions_2(t_map *content, int tmp[]);
int			close_window(t_map *content);
void		keys(int key_code, t_map *content);

/* main */
int			main(int ac, char **av);

/*-fsanitize=address*/
#endif
