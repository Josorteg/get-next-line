/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:39:49 by josorteg          #+#    #+#             */
/*   Updated: 2022/11/16 12:22:24 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

char	*ft_cutline(char *bufferp)
{
	char	*cut_buffer;
	int		i;
	int		j;

	i = 0;
	if (!bufferp[i])
		return (NULL);
	while (bufferp[i] && bufferp[i] != '\n')
		i++;
	if (!bufferp[i])
		return (true_free(&bufferp));
	cut_buffer = ft_calloc ((ft_strlen(bufferp) - i + 2), sizeof(char));
	if (!cut_buffer)
		return (true_free(&bufferp));
	i++;
	j = 0;
	while (bufferp[i])
		cut_buffer[j++] = bufferp[i++];
	true_free(&bufferp);
	cut_buffer[j] = '\0';
	return (cut_buffer);
}

char	*ft_returnline(char *bufferp)
{
	char	*line;
	int		i;

	i = 0;
	if (!bufferp[i])
		return (NULL);
	while (bufferp[i] && bufferp[i] != '\n')
		i++;
	if (bufferp[i])
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (bufferp[i] && bufferp[i] != '\n')
	{
		line[i] = bufferp[i];
		i++;
	}
	if (bufferp[i] && bufferp[i] == '\n')
	{
		line[i] = '\n';
	}
	return (line);
}

char	*ft_addbuffer(char *bufferp, char *buffer)
{
	char	*temp;

	if (!bufferp)
	{
		bufferp = malloc(sizeof(char) * 1);
		if (!bufferp)
			return (NULL);
		bufferp[0] = '\0';
	}
	temp = ft_strjoin(bufferp, buffer);
	true_free(&bufferp);
	return (temp);
}

char	*ft_read(int fd, char *bufferp)
{
	char	buffer[BUFFER_SIZE + 1];
	int		rbyte;

	buffer[0] = '\0';
	rbyte = 25;
	while (rbyte > 0 && !ft_strchr(buffer, '\n'))
	{
		rbyte = read(fd, buffer, BUFFER_SIZE);
		if (rbyte > 0)
		{
			buffer[rbyte] = '\0';
			bufferp = ft_addbuffer(bufferp, buffer);
		}
	}
	if (rbyte == -1)
	{
		return (true_free(&bufferp));
	}
	return (bufferp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_returnline(buffer[fd]);
	if (line == NULL)
		return (true_free(&buffer[fd]));
	buffer[fd] = ft_cutline(buffer[fd]);
	return (line);
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*res;
	int		n;

	n = 0;
	res ="hola";
	fd = open(argv[1], O_RDONLY);
	while (res)
	{

		res = get_next_line(fd);
		printf("line%d = %s",n,res);
		n++;
	}
	close(fd);
	return (0);
}*/
