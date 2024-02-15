NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS = -Wall -Wextra -Werror -Ilibft -lft -Llibft/ -g3
MLX_FLAGS = -ldl -lglfw -pthread -lm

SRCS = main.c read_map.c check_map.c check_map2.c start.c image.c key_moves.c error_free.c

SRCS_BONUS = main_bonus.c read_map_bonus.c check_map_bonus.c check_map2_bonus.c \
				start_bonus.c image_bonus.c key_moves_bonus.c error_free_bonus.c

MLX_URL = https://github.com/codam-coding-college/MLX42.git
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): lib $(SRCS)
	@cc $(CFLAGS) $(SRCS) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): lib $(SRCS_BONUS)
	@cc $(CFLAGS) $(SRCS_BONUS) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

lib: $(MLX) $(LIBFT)

$(MLX):
	@if [ ! -d "MLX42" ]; then \
		git clone $(MLX_URL) && \
		cd MLX42 && cmake -B build && cmake --build build -j4; \
	fi
	@echo $(GREEN)"Building MLX42"$(DEFAULT);

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)
	@rm -rf MLX42

re: fclean all

.PHONY: all, $(LIBFT_PATH)/libft.a, clean, fclean, re $(LIBFT)