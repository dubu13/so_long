/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:40:40 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/15 15:57:58 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_line_length(char *save)
{
	int	len;

	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	return (len);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&(str[i]));
		i++;
	}
	return (0);
}

int	ft_len(char *save, char *buf)
{
	int	len;

	len = ft_strlen_gnl(save) + ft_strlen_gnl(buf);
	return (len);
}

char	*ft_strjoin_gnl(char *save, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (save == NULL)
	{
		save = (char *)malloc(sizeof(char) * (1));
		save[0] = '\0';
	}
	if (!buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_len(save, buf) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_len(save, buf)] = '\0';
	free(save);
	return (str);
}
