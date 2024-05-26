/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:12:13 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 16:53:25 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_file_checker(char *str)
{
	int	i;
	int len;

	i = 0;
	len = slen(str);
	if(len > 4)
	{
		while (str[i])
		{
			if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e' && str[i
					+ 3] == 'r' && str[i + 4] == '\0')
				return (1);
			i++;
		}
	}
	write(1, "Invalid File\n", 13);
	exit(1);
}

int	is_map_rectangular(t_map *content)
{
	int	i;
	int	len;

	i = 0;
	len = slen(content->map[i]);
	while (content->map[i])
	{
		if (len != slen(content->map[i]))
		{
			return (0);
		}
		i++;
	}
	content->columns_in_map = len;
	return (1);
}

int	map_layout(t_map *content, char **av)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(content->map_fd);
	if (tmp == NULL)
		return (0);
	content->rows_in_map = 0;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(content->map_fd);
		content->rows_in_map++;
	}
	close(content->map_fd);
	map_init(content, i, av);
	if (is_map_rectangular(content) && valid_walls(content)
		&& valid_elements(content) && flood_fill(content))
		return (1);
	free_map(content);
	return (0);
}
