/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:43:24 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/26 16:32:58 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	content;

	if (ac != 2)
	{
		write(1, "Wrong Number of arguments\n", 26);
		exit(1);
	}
	data_init(&content);
	if (map_file_checker(av[1]))
	{
		content.map_fd = open(av[1], O_RDONLY);
		if (content.map_fd == -1)
		{
			write(1, "Could not open file\n", 20);
			exit(1);
		}
		if (!map_layout(&content, av))
		{
			close(content.map_fd);
			write(1, "Map invalid\n", 12);
			exit(1);
		}
		write(1,"Map is valid, Starting Game!\n",29);
		mlx_start(&content);
	}
}
