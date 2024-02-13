NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Ilibft -lft -Llibft/ -g3
MLX_FLAGS = -ldl -lglfw -pthread -lm

# SRCS = error_free.c game.c image.c key_moves.c check_map.c check_map2.c read_map.c main.c
SRCS = $(wildcard ./*.c)

MLX_URL = https://github.com/codam-coding-college/MLX42.git
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a



all: $(NAME)

$(NAME): lib $(SRCS) $(MAIN)
	@cc $(CFLAGS) $(SRCS) $(MAIN) $(MLX) $(MLX_FLAGS) -o $(NAME)

lib: $(MLX) $(LIBFT)

$(MLX):
	@git clone $(MLX_URL)
	@cd MLX42 && cmake -B build && cmake --build build


$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf MLX42

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all, $(LIBFT_PATH)/libft.a, clean, fclean, re $(LIBFT)