/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:36:09 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/21 15:18:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_ROWS 50
# define MAX_COLUMNS 50

# include "GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
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
	int		start_pos[2];
	int		exit_pos[2];
	int		found_exit;
	int		found_all_collectibles;
	int		rows_in_map;
	int		columns_in_map;
	int		map_fd;
	int		valid_exit;
	int		collectibles;
	int		player_position;
	int		empty_space;
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

/* floodfill */
int			is_valid_cell(int x, int y, int rows, int cols);
void		flood_fill_recursive(t_map *content, int x, int y,
				int visited[][MAX_COLUMNS]);
int			flood_fill(t_map *content);
void		where_is_player(t_map *content);
void		where_is_exit(t_map *content);

/* utils */
int			slen(const char *s);
void		line_break_eraser(t_map *content);
int			lines_read_counter(t_map *content);

/* main */
int			main(int ac, char **av);

/* get next line */
int			ft_strlen(char *x);
int			ft_clear(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);

/* TESTERS*/
void printCharArray(char **map, int rows);

/*-fsanitize=address*/
#endif
