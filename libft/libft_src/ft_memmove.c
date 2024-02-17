/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/22 18:12:22 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char				*temp;
	unsigned char		*dst2;
	const unsigned char	*src2;

	if (!src && !dst)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * len);
	dst2 = (unsigned char *) dst;
	src2 = (const unsigned char *) src;
	if (temp == NULL)
	{
		return (dst);
	}
	ft_memcpy(temp, src2, len);
	ft_memcpy(dst2, temp, len);
	free (temp);
	return (dst);
}
