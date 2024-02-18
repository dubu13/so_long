NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm

BONUS_DIR = bonus

SRCS = main.c read_map.c check_map.c check_map2.c start.c image.c key_moves.c error_free.c

SRCS_BONUS = $(addprefix $(BONUS_DIR)/, \
			main_bonus.c read_map_bonus.c check_map_bonus.c check_map2_bonus.c \
			start_bonus.c image_bonus.c key_moves_bonus.c player_move.c error_free_bonus.c)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

MLX_URL = https://github.com/codam-coding-college/MLX42.git
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@cc $(CFLAGS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME) $(OBJS) -g3

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@cc $(CFLAGS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME_BONUS) $(OBJS_BONUS) -g3

lib: $(MLX) $(LIBFT)

$(MLX):
	@if [ ! -d "MLX42" ]; then \
		git clone $(MLX_URL) && \
		cd MLX42 && cmake -B build && cmake --build build -j4; \
	fi

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)
	@rm -rf MLX42

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus