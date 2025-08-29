# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhasan <dhasan@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 18:24:15 by dhasan            #+#    #+#              #
#    Updated: 2025/08/29 13:35:31 by dhasan           ###   ########.fr        #
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
		@git submodule update --init --recursive
		@cd MLX42 && cmake -B build > /dev/null && cmake --build build -j4 > /dev/null

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(MLX) $(MLX_FLAGS) $(INCLUDE)
	echo $(GREEN)"Building $(NAME)"$(DEFAULT);

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS) $(MLX)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX) $(MLX_FLAGS) $(INCLUDE)
	echo $(GREEN)"Building $(NAME_BONUS)"$(DEFAULT);

$(LIBFT):
	@git submodule update --init --recursive
	@make -C $(LIBFT_PATH) > /dev/null

$(BINDIR):
	echo $(GREEN)"Creating $(BINDIR) directory"$(DEFAULT);
	mkdir -p $(BINDIR)

$(BINDIR)/%.o: $(SRCS_DIR)/%.c inc/so_long.h | $(BINDIR)
		$(CC) $(CFLAGS) -c $< -o $@
		echo "Compiled $< into $@"

$(BINDIR)/%.o: $(BONUS_DIR)/%.c inc/so_long_bonus.h | $(BINDIR)
		$(CC) $(CFLAGS) -c $< -o $@
		echo "Compiled $< into $@"

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(BINDIR)/*.o
	echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -rf $(BINDIR)
	rm -rf libft
	rm -rf MLX42
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