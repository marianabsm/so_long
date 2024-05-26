/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:21:27 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 20:45:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *content)
{
	int	i;
	
	if (content->map == NULL)
		return;
	i = -1;
	while (content->map[++i])
		free(content->map[i]);
	free(content->map);
}
void	free_mlx(t_map *content)
{
	free(content->mlx->mlx);
	free(content->mlx);
	free(content->img);
}
