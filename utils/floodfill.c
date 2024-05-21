/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:32:23 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/21 16:22:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_cell(int x, int y, int rows, int cols)
{
	return (x > 0 && x < rows - 1 && y > 0 && y < cols - 1);
}

void	flood_fill_recursive(t_map *content, int x, int y,
		int visited[][MAX_COLUMNS])
{
	int	rows;
	int	cols;

	rows = content->rows_in_map;
	cols = content->columns_in_map;
	if (content->map[x][y] == 'E')
		content->found_exit = 1;
	if (!is_valid_cell(x, y, rows, cols) || visited[x][y]
		|| content->map[x][y] == '1' || content->map[x][y] == 'X'
		|| content->map[x][y] == 'E')
		return ;
	visited[x][y] = 1;
	if (content->map[x][y] == 'C')
		(content->found_all_collectibles)++;
	flood_fill_recursive(content, x - 1, y, visited);
	flood_fill_recursive(content, x + 1, y, visited);
	flood_fill_recursive(content, x, y - 1, visited);
	flood_fill_recursive(content, x, y + 1, visited);
}

int	flood_fill(t_map *content)
{
	static int		visited[MAX_ROWS][MAX_COLUMNS] = {0};
	int				start_x;
	int				start_y;

	start_x = content->start_pos[1];
	start_y = content->start_pos[0];
	content->found_all_collectibles = 0;
	flood_fill_recursive(content, start_x, start_y, visited);
	if (content->found_all_collectibles == content->collectibles && content->found_exit == 1)
		return (1);
	else
		return (0);
}

void printCharArray(char **map, int rows) 
{
    for (int i = 0; i < rows; ++i) 
	{
        printf("%s ", map[i]);
        printf("\n");
    }
}


void	where_is_player(t_map *content)
{
	char	**map;
	int		x;
	int		y;

	map = content->map;
	x = 1;
	y = 1;
	while (map[y])
	{	
		x = 1;
		while (map[y][x])
		{	
			if (map[y][x] == 'P')
			{
				content->start_pos[0] = y;
				content->start_pos[1] = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	where_is_exit(t_map *content)
{
	char	**map;
	int		x;
	int		y;

	map = content->map;
	x = 1;
	y = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				content->exit_pos[0] = y;
				content->exit_pos[1] = x;
				return ;
			}
			x++;
		}
		y++;
	}
}


