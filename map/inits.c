/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:11:09 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 22:45:40 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_init(t_map *content)
{
	content->map = NULL;
	content->found_exit = 0;
	content->found_all_collectibles = 0;
	content->rows_in_map = 0;
	content->columns_in_map = 0;
	content->map_fd = 0;
	content->valid_exit = 0;
	content->collectibles = 0;
	content->player_position = 0;
	content->empty_space = 0;
	content->num_of_actions = 0;
}

void	map_init(t_map *content, int i, char **av)
{
	i = 0;
	content->map_fd = open(av[1], O_RDONLY);
	content->map = malloc(sizeof(char *) * (content->rows_in_map + 1));
	content->map[i] = get_next_line(content->map_fd);
	while (content->map[i] != NULL)
	{
		i++;
		content->map[i] = get_next_line(content->map_fd);
	}
	line_break_eraser(content);
}
