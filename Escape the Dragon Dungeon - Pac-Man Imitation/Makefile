
NAME = so_long
cc = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

MLX_PATH = mlx/

SRCS =	ft_utils.c \
		ft_parsing.c \
		ft_so_long.c \
		ft_print.c \
		ft_link_to_files.c \
		ft_flood_fill.c \
		ft_key_bind.c \
		ft_messaging.c \
		ft_init_struct.c \
		ft_split.c \

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(MLX_PATH) clean
	
fclean:	clean
	$(RM) $(NAME)
	make -C $(MLX_PATH) clean
	
re: fclean all
