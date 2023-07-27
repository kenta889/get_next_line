/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenttaka <kenttaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:40:55 by kenttaka          #+#    #+#             */
/*   Updated: 2023/07/27 13:35:33 by kenttaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}	
		dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *save, char *buf)
{
	// size_t	i;
	// size_t	j;
	char	*str;

	if (save == NULL)
	{
		save = (char *)malloc(1);
		if (save == NULL)
			return (NULL);
		save[0] = '\0';
	}
	if (save == NULL || buf == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(save) + ft_strlen(buf) + 1);
	if (str == NULL)
		return (NULL);
	// i = -1;
	// j = 0;
	// while (save[++i] != '\0')
	// 	str[i] = save[i];
	ft_strlcpy(str, save, ft_strlen(save) + 1);
	ft_strlcat(str, buf, ft_strlen(buf) + 1);
	// while (buf[j] != '\0')
	// 	str[i++] = buf[j++];
	str[ft_strlen(save) + ft_strlen(buf)] = '\0';
	free(save);
	return (str);
}

char	*ft_put_line(char *save)
{
	size_t	i;
	char	*str;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	str = (char *)malloc(i + 3);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_save(char *save)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(save) - i + 1);
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}
