/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:02:17 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/07 14:45:18 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1, ssize_t n)
{
	ssize_t	i;
	char	*p;

	p = (char *)malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_put_line(char **line, char **mem, char *buf)
{
	int		flag;
	char	*tmp;
	ssize_t	dest;

	flag = 0;
	dest = ft_strchr(buf, '\n');
	tmp = ft_strjoin(*line, buf, dest);
	if (!tmp)
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	if (buf[dest] == '\n')
	{
		tmp = ft_strdup(&buf[dest + 1], ft_strlen(buf) - dest);
		if (!tmp)
			return (-1);
		flag = 1;
	}
	if (*mem)
		free(*mem);
	*mem = tmp;
	return (flag);
}

int	ft_initialize(char **line, char **mem, char **buf)
{
	int	flag;

	flag = 0;
	*line = (char *)malloc(1);
	if (!*line)
	{
		ft_free_error(line, mem, buf, -1);
		return (-1);
	}
	*line[0] = '\0';
	if (*mem)
		flag = ft_put_line(line, mem, *mem);
	*buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buf)
	{
		ft_free_error(line, mem, buf, -1);
		return (-1);
	}
	return (flag);
}

void	ft_free_error(char **line, char **mem, char **buf, int sign)
{
	if (*buf)
		free(*buf);
	if (sign <= 0)
	{
		if (*mem)
		{
			free(*mem);
			*mem = NULL;
		}
		if (sign == -1)
		{
			if (*line)
			{
				free (*line);
				*line = NULL;
			}
		}
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*mem[10000];
	char		*buf;
	ssize_t		return_value;
	ssize_t		bytes;

	if (fd < 0 || 10000 <= fd || line == NULL)
		return (-1);
	return_value = ft_initialize(line, &mem[fd], &buf);
	if (return_value == -1)
		return (-1);
	bytes = 1;
	while (!return_value && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			return_value = bytes;
		if (0 < bytes)
		{
			buf[bytes] = '\0';
			return_value = ft_put_line(line, &mem[fd], buf);
		}
	}
	ft_free_error(line, &mem[fd], &buf, return_value);
	return ((int)return_value);
}

int	main(int argc, char **argv)
{
	int	fd;
	int fd2;
	char *line;
	int sign;

	(void)argc;
	sign = 0;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	line = NULL;
	while ((sign = get_next_line(fd, &line)) == 1)
	{
		printf("%d: ", sign);
		printf("%s\n", line);
		sign = get_next_line(fd2, &line);
		printf("%d: ", sign);
		printf("%s\n", line);
	}
	printf("%d: ", sign);
	printf("%s\n", line);
	return (0);
}