/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:01:12 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/13 16:29:04 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_dick(char *content)
{
	int		i;
	char	*line;

	i = 0;
	if (!get_strlen(content))
	{
		if (content)
			free(content);
		return (NULL);
	}
	while (content[i] != '\n' && content[i] != '\0')
	{
		i++;
	}
	if (content[i] == '\0')
		i--;
	line = get_substr(content, 0, i + 1, 0);
	return (line);
}

char	*r_file(int fd, char *content)
{
	char	*tmp;
	int		line_s;

	tmp = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	line_s = 1;
	while (!get_strchr(content, '\n') && line_s)
	{
		line_s = read(fd, tmp, BUFFER_SIZE);
		if (line_s < 0)
		{
			free(tmp);
			free(content);
			return (NULL);
		}
		tmp[line_s] = '\0';
		content = get_strjoin(content, tmp);
	}
	free(tmp);
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;
	int			line_len;
	int			content_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	content = r_file(fd, content);
	line = get_dick(content);
	if (!line)
	{
		content = NULL;
		return (NULL);
	}
	line_len = get_strlen(line);
	content_len = get_strlen(content);
	content = get_substr(content, line_len, content_len - line_len, 1);
	return (line);
}

// int	main(void)
// {
// 	int fd = 0;
// 	char *line;
// 	fd = open("tex.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("Gnl:%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	fd = open("tex.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("Gnl:%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }