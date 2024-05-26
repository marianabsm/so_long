/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:18:38 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 22:43:54 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_start(t_map *content)
{
	content->running = 1;
	content->mlx = malloc(sizeof(t_mlx));
	if (!content->mlx)
		return ;
	content->mlx->mlx = mlx_init();
	if (!content->mlx->mlx)
	{
		free(content->mlx);
		return ;
	}
	content->mlx->window = mlx_new_window(content->mlx->mlx,
			content->columns_in_map * 64, (content->rows_in_map - 1) * 64,
			"./so_long");
	if (!content->mlx->window)
	{
		free(content->mlx);
		return ;
	}
	mlx_key_hook(content->mlx->window, actions, content);
	mlx_hook(content->mlx->window, 17, 0L, close_window, content);
	content->img = malloc(sizeof(t_img));
	if (!content->img)
	{
		free(content->mlx);
		return ;
	}
	content->img->img = mlx_new_image(content->mlx->mlx, 64, 64);
	if (!content->img->img)
	{
		free(content->img);
		free(content->mlx);
		return ;
	}
	mlx_loop_hook(content->mlx->mlx, find_element, content);
	mlx_loop(content->mlx->mlx);
	free(content->img);
	free(content->mlx);
}
