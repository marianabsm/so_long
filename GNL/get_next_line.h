/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:01:45 by gcapa-pe          #+#    #+#             */
/*   Updated: 2024/05/26 20:14:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
char	*get_strchr(char *s, int c);
char	*get_strjoin(char *s1, char *s2);
int		get_strlen(char *s);
char	*get_substr(char *s, int start, int len, int do_free);
char	*bleh(char *content);
char	*ft_sub_divide(char *s, char *sub_s, int start, int len);

#endif
