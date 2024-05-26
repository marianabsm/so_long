/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:18:38 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 16:51:36 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Assuming you have structures t_map, t_mlx, and t_img defined somewhere

void	mlx_start(t_map *content)
{	
    content->running = 1;

    // Allocate and initialize the mlx structure
    content->mlx = malloc(sizeof(t_mlx));
    if (!content->mlx) {
        write(2, "Failed to allocate memory for mlx\n", 34);
        return;
    }

    content->mlx->mlx = mlx_init();
    if (!content->mlx->mlx) {
        write(2, "Failed to initialize mlx\n", 25);
        free(content->mlx);
        return;
    }

    // Create the window
    content->mlx->window = mlx_new_window(content->mlx->mlx, content->columns_in_map * 64,
                                          (content->rows_in_map - 1) * 64, "./so_long");
    if (!content->mlx->window) {
        write(2, "Failed to create window\n", 24);
        free(content->mlx);
        return;
    }

    // Set up event hooks
    mlx_key_hook(content->mlx->window, actions, content);
    mlx_hook(content->mlx->window, 17, 0L, close_window, content);

    // Allocate and initialize the image structure
    content->img = malloc(sizeof(t_img));
    if (!content->img) {
        write(2, "Failed to allocate memory for img\n", 34);
        free(content->mlx);
        return;
    }

    content->img->img = mlx_new_image(content->mlx->mlx, 64, 64);
    if (!content->img->img) {
        write(2, "Failed to create image\n", 23);
        free(content->img);
        free(content->mlx);
        return;
    }

    // Set up the loop hook
    mlx_loop_hook(content->mlx->mlx, find_element, content);

    // Start the MLX event loop
    mlx_loop(content->mlx->mlx);

    // Cleanup (though this will never be reached since mlx_loop is infinite)
    // Free img struct
    free(content->img);
    // Free mlx struct
    free(content->mlx);
}

