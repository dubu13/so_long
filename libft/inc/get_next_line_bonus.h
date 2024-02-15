/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:40:33 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/15 15:58:08 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1025
# endif

char	*get_next_line(int fd);
char	*read_data(int fd, char *save);
char	*take_line(char *save);
char	*delete_line(char *save);

int		ft_line_length(char *save);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char *str);
int		ft_len(char *save, char *buf);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif