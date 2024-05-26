/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:21:27 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 22:40:02 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *content)
{
	int	i;

	if (content->map == NULL)
		return ;
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
