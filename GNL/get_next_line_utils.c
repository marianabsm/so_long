/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:01:33 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/06/13 16:29:40 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = get_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_sub_divide(char *s, char *sub_s, int start, int len)
{
	if (start > get_strlen(s))
	{
		sub_s = malloc(sizeof(char));
		if (!sub_s)
			return (NULL);
		sub_s[0] = '\0';
		return (sub_s);
	}
	else if (len >= get_strlen(s))
		sub_s = malloc(get_strlen(s) - start + 1);
	else
		sub_s = malloc(len + 1);
	if (!sub_s)
		free(sub_s);
	return (sub_s);
}

char	*get_substr(char *s, int start, int len, int do_free)
{
	char	*sub_s;
	int		i;
	int		j;

	sub_s = 0;
	i = -1;
	j = 0;
	sub_s = ft_sub_divide(s, sub_s, start, len);
	while (s[++i] != '\0')
	{
		if (i >= start && j < len)
			sub_s[j++] = s[i];
	}
	sub_s[j] = '\0';
	if (do_free)
		free(s);
	return (sub_s);
}

char	*get_strjoin(char *s1, char *s2)
{
	char	*conc;
	int		i;
	int		j;

	i = 0;
	conc = (char *)malloc(get_strlen(s1) + get_strlen(s2) + 1);
	if (!conc)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			conc[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] != '\0')
		conc[i++] = s2[j++];
	conc[i] = '\0';
	free(s1);
	return (conc);
}

int	get_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
