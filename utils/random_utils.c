/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:00:50 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/28 14:08:32 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	slen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	line_break_eraser(t_map *content)
{
	int	i;
	int	j;

	i = 0;
	while (content->map[i] != NULL)
	{
		j = 0;
		while (content->map[i][j] != '\0')
		{
			if (content->map[i][j] == '\n')
				content->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

int	lines_read_counter(t_map *content)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(content->map_fd);
	while (line)
	{
		i++;
		free(line);
	}
	return (i);
}

int	valid_elements(t_map *content)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = valid_exit(content);
	b = collectible(content);
	c = empty_space(content);
	d = player_position(content);
	where_is_player(content);
	where_is_exit(content);
	e = valid_map_elements(content);
	if (a == 1 && b >= 1 && c >= 1 && d == 1 && e == 1)
		return (1);
	return (0);
}
