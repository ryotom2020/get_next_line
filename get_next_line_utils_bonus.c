/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:02:35 by rtomiki           #+#    #+#             */
/*   Updated: 2021/05/07 12:15:34 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(s1) + n + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

ssize_t	ft_strchr(const char *s, int c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (i);
}
