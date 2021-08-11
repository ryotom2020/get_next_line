/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:02:34 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/06 13:10:14 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2, size_t n);
ssize_t	ft_strlen(const char *s);
ssize_t	ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1, ssize_t n);
int		ft_put_line(char **line, char **mem, char *buf);
void	ft_free_error(char **line, char **mem, char **buf, int sign);
int		ft_initialize(char **line, char **mem, char **buf);

#endif
