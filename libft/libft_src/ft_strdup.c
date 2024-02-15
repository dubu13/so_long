/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/22 20:43:01 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*src;
	char		*dst;
	int			len;

	len = ft_strlen(s1);
	src = s1;
	dst = malloc(len * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, len + 1);
	return (dst);
}
