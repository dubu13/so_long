# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 18:24:15 by dhasan            #+#    #+#              #
#    Updated: 2024/06/02 18:37:05 by dhasan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -g3
MLX_FLAGS = -ldl -lglfw -pthread -lm

INCLUDE = -L $(LIBFT_PATH) -lft

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

BINDIR = bin
SRCS_DIR = src
BONUS_DIR = bonus

SRCS = $(addprefix $(SRCS_DIR)/, \
		main.c read_map.c check_map.c check_map2.c start.c image.c key_moves.c error_free.c)

SRCS_BONUS = $(addprefix $(BONUS_DIR)/, \
			main_bonus.c read_map_bonus.c check_map_bonus.c check_map2_bonus.c \
			start_bonus.c image_bonus.c key_moves_bonus.c player_move.c error_free_bonus.c)

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(BINDIR)/%.o)

OBJS_BONUS = $(SRCS_BONUS:$(BONUS_DIR)/%.c=$(BINDIR)/%.o)

MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

all: $(NAME)

bonus: $(NAME_BONUS)

.SILENT:

$(MLX):
		cd MLX42 && cmake -B build && cmake --build build -j4;

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(INCLUDE)
	echo $(GREEN)"Building $(NAME)"$(DEFAULT);

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME_BONUS) $(OBJS_BONUS) $(INCLUDE)
	echo $(GREEN)"Building $(NAME_BONUS)"$(DEFAULT);

$(LIBFT):
	make -C $(LIBFT_PATH)

$(BINDIR):
	echo $(GREEN)"Creating $(BINDIR) directory"$(DEFAULT);
	mkdir -p $(BINDIR)

$(BINDIR)/%.o: $(SRCS_DIR)/%.c inc/so_long.h | $(BINDIR)
		$(CC) $(CFLAGS) -c $< -o $@
		echo "Compiled $< into $@"

$(BINDIR)/%.o: $(BONUS_DIR)/%.c inc/so_long_bonus.h | $(BINDIR)
		$(CC) $(CFLAGS) -c $< -o $@
		echo "Compiled $< into $@"

submodule:
	git submodule update --init --recursive

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(BINDIR)/*.o
	echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -rf $(BINDIR)
	make fclean -C $(LIBFT_PATH)
	echo $(RED)"Removing $(NAME) / $(NAME_BONUS) "$(DEFAULT);

re: fclean all
	echo $(GREEN)"Rebuilding everything"$(DEFAULT);

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus

# Colours
DEFAULT = "\033[39m"
GREEN = "\033[32m"
RED = "\033[31m"