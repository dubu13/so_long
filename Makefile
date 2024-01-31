NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Ilibft -lft -Llibft/
MLX_FLAGS = -ldl -lglfw -pthread -lm

SRCS = check.c error_free.c game.c image.c key_moves.c map.c so_long.c utils.c

MLX_URL = https://github.com/codam-coding-college/MLX42.git
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): lib $(SRCS) $(MAIN)
	cc $(CFLAGS) $(SRCS) $(MAIN) $(MLX) $(MLX_FLAGS) -o $(NAME)

lib: $(MLX) $(LIBFT)
.PHONY: lib $(LIBFT)

$(MLX):
	git clone $(MLX_URL)
	cd MLX42 && cmake -B build && cmake --build build


$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf MLX42

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all