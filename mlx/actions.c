/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:50:45 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 16:45:16 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	actions(int key_code, t_map *content)
{
	int	tmp[2];

	tmp[0] = content->start_pos[0];
	tmp[1] = content->start_pos[1];
	if (content->map[content->start_pos[0]][content->start_pos[1]] == '1')
		return (0);
	keys(key_code, content);
	if (content->map[content->start_pos[0]][content->start_pos[1]] == 'C')
		content->collectibles--;
	actions_2(content, tmp);
	content->num_of_actions += 1;
	if (content->start_pos[0] != tmp[0] || content->start_pos[1] != tmp[1])
		content->map[tmp[0]][tmp[1]] = '0';
	return (0);
}

int	actions_2(t_map *content, int tmp[])
{
	if (content->map[content->start_pos[0]][content->start_pos[1]] == '1'
		|| (content->map[content->start_pos[0]][content->start_pos[1]] == 'E'
			&& content->collectibles > 0))
	{
		content->start_pos[0] = tmp[0];
		content->start_pos[1] = tmp[1];
		return (0);
	}
	else if (content->map[content->start_pos[0]][content->start_pos[1]] == 'X')
	{
		write(1, "\n\033[31mYour CutieCat's string has been cut! :(\033[0m",
			20);
		close_window(content);
	}
	else if (content->map[content->start_pos[0]][content->start_pos[1]] == 'E'
		&& content->collectibles == 0)
	{
		write(1, "\n\033[32mYour CutieCat's got it's bow!\033[0m\n", 13);
		close_window(content);
	}
	content->num_of_actions += 1;
	return (0);
}

int	close_window(t_map *content)
{
	free_map(content);
	content->running = 0;
	mlx_destroy_window(content->mlx->mlx, content->mlx->window);
	mlx_destroy_image(content->mlx->mlx, content->img->img);
	// mlx_loop_end(content->mlx->mlx);
	// mlx_destroy_display(content->mlx->mlx);
	free(content->mlx->mlx);
	free(content->mlx);
	free(content->img);
	exit(0);
}

void	keys(int key_code, t_map *content)
{
	if (key_code == ESC)
		close_window(content);
	else if (key_code == UP)
		content->start_pos[0]--;
	else if (key_code == DOWN)
		content->start_pos[0]++;
	else if (key_code == LEFT)
		content->start_pos[1]--;
	else if (key_code == RIGHT)
		content->start_pos[1]++;
}
