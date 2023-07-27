/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenttaka <kenttaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:49:39 by kenttaka          #+#    #+#             */
/*   Updated: 2023/07/27 13:18:35 by kenttaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*ft_read_to_save(int fd, char *save)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(BUFFER_SIZE + 2);
	if (buf == NULL)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr(save, '\n') == 0 && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = ft_read_to_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = ft_put_line(save);
	save = ft_new_save(save);
	return (line);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }

// int	main(void)
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("test2", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	int i = 0;
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		printf("<--%d, %s-->\n", i, str);
// 		i++;
// 		free(str);
// 		if (i == 15)
// 			break ;
// 	}
// 	str = get_next_line(fd);
// 	close(fd);
// 	return (0);
// }
