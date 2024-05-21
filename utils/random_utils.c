/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:00:50 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/21 15:22:59 by marvin           ###   ########.fr       */
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
	int		i;
	int		j;

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
