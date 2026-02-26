# Project / Tools
# =========================
CC       := cc
RM       := rm -f
CFLAGS   := -g -Wall -Wextra -Werror
LDFLAGS  := -lmlx -lX11 -lXext -lm -lbsd

# =========================
# Libraries
# =========================
LIBFT_DR := libft
LIBFT    := $(LIBFT_DR)/libft.a

MLX_DIR  := mlx
MLX      := $(MLX_DIR)/libmlx.a

INCLUDES       = -I. -I$(SRC_DIR_BASIC) -I$(SRC_DIR_BONUS) -I$(LIBFT_DR) -I$(MLX_DIR)
HEADERS_BASIC  = $(SRC_DIR_BASIC)/cub3D.h
HEADERS_BONUS  = $(SRC_DIR_BONUS)/cub3D_bonus.h

# =========================
# Variants
# =========================
NAME        := cub3D
BONUS_NAME  := cub3D_bonus

SRC_DIR_BASIC := basic
SRC_DIR_BONUS := bonus

OBJ_DIR       := obj
OBJ_DIR_BASIC := $(OBJ_DIR)/basic
OBJ_DIR_BONUS := $(OBJ_DIR)/bonus

# =========================
# Source files (explicit lists, no wildcards)
# =========================
# Example: adjust to your actual file layout
SRCS_BASIC := \
	$(SRC_DIR_BASIC)/main.c \
	$(SRC_DIR_BASIC)/utils/ft_args_validation.c \
	$(SRC_DIR_BASIC)/utils/ft_file_reader.c \
	$(SRC_DIR_BASIC)/utils/ft_display.c \
	$(SRC_DIR_BASIC)/utils/ft_param_parser.c \
	$(SRC_DIR_BASIC)/utils/ft_texture_utils.c \
	$(SRC_DIR_BASIC)/utils/ft_rgb_utils.c \
	$(SRC_DIR_BASIC)/utils/ft_map_validation.c \
	$(SRC_DIR_BASIC)/utils/ft_map_parser.c \
	$(SRC_DIR_BASIC)/utils/ft_map_prep.c \
	$(SRC_DIR_BASIC)/utils/ft_prepare_to_fill.c \
	$(SRC_DIR_BASIC)/utils/ft_map_enclosure.c \
	$(SRC_DIR_BASIC)/utils/ft_data_validation.c \
	$(SRC_DIR_BASIC)/utils/ft_utils.c \
	$(SRC_DIR_BASIC)/utils/ft_string_utils.c \
	$(SRC_DIR_BASIC)/utils/ft_validation_utils.c \
	$(SRC_DIR_BASIC)/utils/ft_init.c \
	$(SRC_DIR_BASIC)/gnl/ft_gnl.c \
	$(SRC_DIR_BASIC)/gnl/ft_gnl_utils.c \
	$(SRC_DIR_BASIC)/data_validation/ft_game_start.c \
	$(SRC_DIR_BASIC)/exit_error/ft_exit.c \
	$(SRC_DIR_BASIC)/exit_error/ft_free.c \
	$(SRC_DIR_BASIC)/exit_error/ft_messaging.c \
	$(SRC_DIR_BASIC)/player_action/ft_keyhook.c \
	$(SRC_DIR_BASIC)/player_action/ft_movment.c \
	$(SRC_DIR_BASIC)/raycast_engine/ft_raycaster_1.c \
	$(SRC_DIR_BASIC)/raycast_engine/ft_raycaster_2.c \
	$(SRC_DIR_BASIC)/raycast_engine/ft_dda.c


SRCS_BONUS := \
	$(SRC_DIR_BONUS)/main.c \
	$(SRC_DIR_BONUS)/utils/ft_args_validation.c \
	$(SRC_DIR_BONUS)/utils/ft_file_reader.c \
	$(SRC_DIR_BONUS)/utils/ft_display.c \
	$(SRC_DIR_BONUS)/utils/ft_param_parser.c \
	$(SRC_DIR_BONUS)/utils/ft_texture_utils.c \
	$(SRC_DIR_BONUS)/utils/ft_rgb_utils.c \
	$(SRC_DIR_BONUS)/utils/ft_map_validation.c \
	$(SRC_DIR_BONUS)/utils/ft_map_parser_1.c \
	$(SRC_DIR_BONUS)/utils/ft_map_parser_2.c \
	$(SRC_DIR_BONUS)/utils/ft_map_prep.c \
	$(SRC_DIR_BONUS)/utils/ft_prepare_to_fill.c \
	$(SRC_DIR_BONUS)/utils/ft_map_enclosure.c \
	$(SRC_DIR_BONUS)/utils/ft_data_validation.c \
	$(SRC_DIR_BONUS)/utils/ft_utils.c \
	$(SRC_DIR_BONUS)/utils/ft_string_utils.c \
	$(SRC_DIR_BONUS)/utils/ft_validation_utils.c \
	$(SRC_DIR_BONUS)/utils/ft_init_1.c \
	$(SRC_DIR_BONUS)/utils/ft_init_2.c \
	$(SRC_DIR_BONUS)/gnl/ft_gnl.c \
	$(SRC_DIR_BONUS)/gnl/ft_gnl_utils.c \
	$(SRC_DIR_BONUS)/data_validation/ft_game_start_1.c \
	$(SRC_DIR_BONUS)/data_validation/ft_game_start_2.c \
	$(SRC_DIR_BONUS)/items/ft_coin_textures_1.c \
	$(SRC_DIR_BONUS)/items/ft_coin_textures_2.c \
	$(SRC_DIR_BONUS)/items/ft_coin_textures_3.c \
	$(SRC_DIR_BONUS)/items/ft_coin_textures_4.c \
	$(SRC_DIR_BONUS)/exit_error/ft_exit.c \
	$(SRC_DIR_BONUS)/exit_error/ft_free.c \
	$(SRC_DIR_BONUS)/exit_error/ft_messaging.c \
	$(SRC_DIR_BONUS)/player_action/ft_keyhook_1.c \
	$(SRC_DIR_BONUS)/player_action/ft_keyhook_2.c \
	$(SRC_DIR_BONUS)/player_action/ft_mouse_1.c \
	$(SRC_DIR_BONUS)/player_action/ft_mouse_2.c \
	$(SRC_DIR_BONUS)/player_action/ft_movment_1.c \
	$(SRC_DIR_BONUS)/player_action/ft_movment_2.c \
	$(SRC_DIR_BONUS)/items/ft_door_1.c \
	$(SRC_DIR_BONUS)/items/ft_door_2.c \
	$(SRC_DIR_BONUS)/items/ft_coins_1.c \
	$(SRC_DIR_BONUS)/items/ft_coins_2.c \
	$(SRC_DIR_BONUS)/items/ft_coins_3.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_raycaster_1.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_raycaster_2.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_raycaster_3.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_raycaster_4.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_dda_1.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_dda_2.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_coin_render_1.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_coin_render_2.c \
	$(SRC_DIR_BONUS)/raycast_engine/ft_coin_render_3.c \
	$(SRC_DIR_BONUS)/minimap/ft_minimap_1.c \
	$(SRC_DIR_BONUS)/minimap/ft_minimap_2.c \
	$(SRC_DIR_BONUS)/minimap/ft_minimap_3.c \
	$(SRC_DIR_BONUS)/minimap/ft_minimap_4.c

# Convert to objects
OBJS_BASIC := $(SRCS_BASIC:$(SRC_DIR_BASIC)/%.c=$(OBJ_DIR_BASIC)/%.o)
OBJS_BONUS := $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

# Compute *directories* needed for those objects
BASIC_DIRS := $(sort $(dir $(OBJS_BASIC)))
BONUS_DIRS := $(sort $(dir $(OBJS_BONUS)))

# ----- Directory creators (no wildcards, no find) -----
$(OBJ_DIR):
	@mkdir -p $@

dirs_basic: | $(OBJ_DIR)
	@mkdir -p $(BASIC_DIRS)
	@echo "Created object directories for BASIC"

dirs_bonus: | $(OBJ_DIR)
	@mkdir -p $(BONUS_DIRS)
	@echo "Created object directories for BONUS"

# =========================
# Default target
# =========================
.PHONY: all bonus clean fclean re libs
.DEFAULT_GOAL := all

all: $(NAME)

bonus: $(BONUS_NAME)

# =========================
# Libraries
# =========================
libs: $(LIBFT) $(MLX)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# =========================
# Linking
# =========================
$(NAME): $(OBJS_BASIC) $(LIBFT) $(MLX) | dirs_basic
	@$(CC) $(CFLAGS) $(OBJS_BASIC) -L$(LIBFT_DR) -lft -L$(MLX_DIR) $(LDFLAGS) -o $@
	@$(RM) $(BONUS_NAME)
	@echo "Built $(NAME)"

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT) $(MLX) | dirs_bonus
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DR) -lft -L$(MLX_DIR) $(LDFLAGS) -o $@
	@$(RM) $(NAME)
	@echo "Built $(BONUS_NAME)"


# =========================
# Compilation rules
# =========================
$(OBJ_DIR_BASIC)/%.o: $(SRC_DIR_BASIC)/%.c $(HEADERS_BASIC)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(HEADERS_BONUS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =========================
# Cleaning
# =========================
clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DR) clean
	@$(MAKE) -C $(MLX_DIR) clean || true
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DR) fclean
	@$(MAKE) -C $(MLX_DIR) clean || true
	@echo "Cleaned everything"

re: fclean all

t0:
	valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes ./cub3D maps/valid/+ve_1.cub

t1: 
	./cub3D maps/valid/+ve_1.cub

r1: ${NAME}
	for map in maps/valid/*.cub; do echo -n "$$map" ": ";./cub3D "$$map";echo "\n";  done

r11: ${NAME}
	for map in maps/valid/*.cub; do echo -n "$$map" ": ";valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes ./cub3D "$$map";echo "\n";  done

v1: ${NAME}
	for map in maps/invalid/*.cub; do echo -n "$$map" ": ";valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes ./cub3D "$$map";echo "\n";  done
	
b1: 
	valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes ./cub3D_bonus maps/Bonus_map1.cub