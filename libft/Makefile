# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 19:41:34 by dhasan            #+#    #+#              #
#    Updated: 2024/02/06 14:47:27 by dhasan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc

GNL_DIR = gnl_src
PRINTF_DIR = printf_src
LIBFT_DIR = libft_src

LIBFT_SRCS = $(addprefix $(LIBFT_DIR)/, \
		ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_memchr.c ft_memcpy.c ft_memset.c ft_putendl_fd.c \
		ft_putstr_fd.c ft_strchr.c ft_striteri.c  ft_strlcat.c \
		ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c \
		ft_toupper.c ft_atoi.c ft_calloc.c ft_isalpha.c \
		ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memmove.c \
		ft_putchar_fd.c ft_putnbr_fd.c ft_split.c ft_strdup.c \
		ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c \
		ft_strtrim.c ft_tolower.c ft_split.c)

GNL_SRCS = $(addprefix $(GNL_DIR)/, \
		get_next_line_bonus.c get_next_line_utils_bonus.c)


PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/, \
		ft_print_csid.c ft_print_hex.c ft_printf.c ft_check_format.c ft_itoa_2.c)

SRCS = $(LIBFT_SRCS) $(GNL_SRCS) $(PRINTF_SRCS)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
