/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:12:13 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 21:05:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int map_file_checker(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    if (len < 4)
    {
        write(1, "Invalid File\n", 13);
        exit(1);
    }
    if (str[len - 4] == '.' && str[len - 3] == 'b' && str[len - 2] == 'e' && str[len - 1] == 'r')
        return 1;

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
		i++;
	}
	free(tmp);
	close(content->map_fd);
	map_init(content, i, av);
	if (is_map_rectangular(content) && valid_walls(content)
	&& valid_elements(content) && flood_fill(content))
		return (1);
	else
	 	free_map(content);
	return (0);
}
