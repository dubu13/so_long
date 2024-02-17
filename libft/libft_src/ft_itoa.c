/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/22 19:44:52 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
{
	long	len;
	long	num;

	len = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*str;
	int		sign;

	sign = 1;
	num = n;
	len = num_len(n);
	str = malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
		sign = -1;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = '0' + ((num * sign) % 10);
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
