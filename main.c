/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:43:24 by marianamest       #+#    #+#             */
/*   Updated: 2024/05/21 16:26:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	content;

	if (ac != 2)
	{
		perror("Wrong Number of arguments\n");
		exit(1);
	}
	data_init(&content);
	if (map_file_checker(av[1]))
	{
		content.map_fd = open(av[1], O_RDONLY);
		if (content.map_fd == -1)
		{
			perror("Could not open file");
			exit(1);
		}
		if (!map_layout(&content, av))
		{
			close(content.map_fd);
			perror("Map invalid\n");
			exit(1);
		}
		write(1,"Map is valid, Starting Game!\n",30);
	}
}
