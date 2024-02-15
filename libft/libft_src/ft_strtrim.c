/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/21 22:09:51 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_and_copy(const char *s, int start, int len)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (len > i)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;
	int		len;
	int		new_len;

	len = ft_strlen(s1);
	start = 0;
	end = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = len - 1;
	while (end > start && ft_strrchr(set, s1[end]))
		end--;
	new_len = end - start + 1;
	new = malloc_and_copy(s1, start, new_len);
	return (new);
}
