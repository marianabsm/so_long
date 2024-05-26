/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:59:18 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/22 10:55:36 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_top_wall(t_map *content)
{
	char	**map;
	int		i;
	int		j;
	int		len;

	map = content->map;
	i = 0;
	j = 0;
	len = slen(content->map[0]);
	while (i < len)
	{
		if (map[0][i] == '1')
			j++;
		i++;
	}
	if (j == len)
	{	
		return (1);
	}
	return (0);
}

int	valid_middle_walls(t_map *content)
{
	char	**map;
	int		len;
	int		j;

	map = content->map;
	j = 1;
	len = slen(content->map[j]);
	while (j != content->rows_in_map - 1)
	{	
		if(map[j][0] == '1' && map[j][len - 1] == '1')
			j++;
		else	
			return(0);
	}
	return(1);
}

int	valid_bottom_wall(t_map *content)
{
	char	**map;
	int		rows;
	int		i;
	
	map = content->map;
	rows = content->rows_in_map;
	i = 0;
	while (i != content->columns_in_map)
	{	
		
		if (map[rows - 1][i] != '1')
			return(0);
		i++;
	}
	return(1);
}

int	valid_walls(t_map *content)
{
	int	a;
	int	b;
	int	c;

	a = valid_top_wall(content);
	b = valid_middle_walls(content);
	c = valid_bottom_wall(content);
	if (a == 1 && b == 1 && c == 1)
	{
		return (1);
	}
	return (0);
}
