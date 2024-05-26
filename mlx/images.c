/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:24:11 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 18:57:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_to_window(t_map *content, int x, int y)
{
	mlx_put_image_to_window(content->mlx->mlx, content->mlx->window,
		content->img->img, y * 64, x * 64);
	if (content->str_of_actions != NULL)
		free(content->str_of_actions);
}

void	images_to_map1(t_map *content, char element, int x, int y)
{
	mlx_destroy_image(content->mlx->mlx, content->img->img);
	if (element == 'E')
	{
		if (content->collectibles != 0)
			content->img->img = mlx_xpm_file_to_image(content->mlx->mlx,
					"./pics/bed.xpm", &content->img->img_width,
					&content->img->img_height);
	}
	else
		images_to_map2(content, element);
	content->str_of_actions = ft_itoa(content->num_of_actions);
	mlx_string_put(content->mlx->mlx, content->mlx->window,
		content->columns_in_map, content->rows_in_map, 0xFFFFFF,
		content->str_of_actions);
	image_to_window(content, x, y);
}

void	images_to_map2(t_map *content, char element)
{
	if (element == '0')
		content->img->img = mlx_xpm_file_to_image(content->mlx->mlx, "./pics/background.xpm",
				&content->img->img_width, &content->img->img_height);
	else if (element == '1')
		content->img->img = mlx_xpm_file_to_image(content->mlx->mlx, "./pics/wall.xpm",
				&content->img->img_width, &content->img->img_height);
	else if (element == 'P')
		content->img->img = mlx_xpm_file_to_image(content->mlx->mlx,
				"./pics/cat.xpm", &content->img->img_width,
				&content->img->img_height);
	else if (element == 'X')
		scissors_loop(content);
	else if (element == 'C')
		content->img->img = mlx_xpm_file_to_image(content->mlx->mlx,
				"./pics/ball.xpm", &content->img->img_width,
				&content->img->img_height);
}
