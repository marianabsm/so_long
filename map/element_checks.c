/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:18:10 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/28 14:08:20 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_exit(t_map *content)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	map = content->map;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
			{
				if (!content->valid_exit)
					content->valid_exit = 1;
				else
					return (0);
			}
			i++;
		}
		j++;
	}
	return (content->valid_exit);
}

int	collectible(t_map *content)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = content->map;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				(content->collectibles)++;
			i++;
		}
		j++;
	}
	return (content->collectibles);
}

int	empty_space(t_map *content)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = content->map;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0')
			{
				if (!content->empty_space)
					content->empty_space = 1;
			}
			i++;
		}
		j++;
	}
	return (content->empty_space);
}

int	player_position(t_map *content)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	i = 0;
	map = content->map;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				if (!content->player_position)
					content->player_position = 1;
				else
					return (0);
			}
			i++;
		}
		j++;
	}
	return (content->player_position);
}

int	valid_map_elements(t_map *content)
{
	int		i;
	int		j;
	char	current;

	j = 0;
	i = 0;
	while (j < content->rows_in_map)
	{
		i = 0;
		while (i < content->columns_in_map)
		{
			current = content->map[j][i];
			if (current != 'P' && current != 'E' && current != 'C'
				&& current != '0' && current != '1' && current != 'X')
			{
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}
