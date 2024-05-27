/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:16:42 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/27 01:30:51 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	scissors_loop(t_map *content)
{
	static int	i = 0;
	char		*img_fr[2];
	int			num_frames;
	int			frame_index;

	frame_index = 0;
	num_frames = 2;
	img_fr[0] = "pics/closed_sci.xpm";
	usleep(5000);
	img_fr[1] = "pics/open_sci.xpm";
	frame_index = i / (content->scissors + 1) % num_frames;
	content->img->img = mlx_xpm_file_to_image(content->mlx->mlx,
			img_fr[frame_index], &content->img->img_width,
			&content->img->img_height);
	i++;
}

int	find_element(t_map *content)
{
	int	i;
	int	j;

	i = 0;
	while (content->map[i])
	{
		j = 0;
		while (content->map[i][j])
		{
			images_to_map1(content, content->map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (0);
}
