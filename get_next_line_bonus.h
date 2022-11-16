/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:05:30 by josorteg          #+#    #+#             */
/*   Updated: 2022/11/11 16:53:58 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 504
# endif

char		*ft_cutline(char *butterp);
char		*ft_returnline(char *bufferp);
char		*ft_addbuffer(char *bufferp, char *buffer);
char		*ft_read(int fd, char *buffer);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
char		*true_free(char **str);

#endif
