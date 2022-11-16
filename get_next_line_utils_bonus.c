/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:33:54 by josorteg          #+#    #+#             */
/*   Updated: 2022/11/11 13:35:31 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"
#include <stdio.h>

char	*true_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	large;

	large = ft_strlen(s);
	i = 0;
	while (i <= large)
	{
		if (s[i] == (const char) c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*s;
	unsigned int	count;
	size_t			i;
	size_t			j;

	count = ft_strlen(s1) + ft_strlen(s2) + 2;
	s = malloc (count * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*s;
	unsigned int	i;

	i = 0;
	s = malloc (count * size);
	if (!s)
		return (NULL);
	while (i < size * count)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
