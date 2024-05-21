/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:18:10 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/21 16:23:36 by marvin           ###   ########.fr       */
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
	{	i = 0;
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

int	valid_elements(t_map *content)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = valid_exit(content);
	b = collectible(content);
	c = empty_space(content);
	d = player_position(content);
	where_is_player(content);
	where_is_exit(content);
	if (a == 1 && b >= 1 && c >= 1 && d == 1)
	{
		return (1);
	}
	return (0);
}
