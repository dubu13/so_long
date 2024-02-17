/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/22 21:09:03 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (dstsize != 0)
	{
		while (dst[i] != '\0' && i < dstsize)
			i++;
		while (src[j] != '\0' && i < (dstsize - 1))
			dst[i++] = src[j++];
		if (i < dstsize)
			dst[i] = '\0';
		len = i;
		while (src[j])
		{
			j++;
			len++;
		}
		return (len);
	}
	else
		return (ft_strlen(src));
}
