NAME	= cub3D
CFLAGS	= -Wall -Wextra -Werror
LIBMLX	= ./lib/MLX42
RPTINTF	= ./lib/ft_rprintf
GNL		= ./lib/get_next_line

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(GNL)/gnl.a $(RPTINTF)/libftprintf.a $(LIBMLX)/libmlx42.a -ldl -lglfw -L "/users/"$$USER"/.brew/opt/glfw/lib/" -pthread -lm

SRCS =	src/main.c\
		src/mlx_init.c\
		src/mlx_color_pixel.c\
		src/map/minimap.c\
		src/map/map_init.c\
		src/map/map_utils.c\
		src/map/map_player.c\
		src/action/player_action.c\
		src/action/mlx_input.c\
		src/action/player_move.c\
		src/action/player_hitbox.c\
		src/action/player_position.c\
		src/action/time_utils.c\
		src/raycast/init_raycast.c\
		src/raycast/raycast_utils.c\
		src/raycast/draw_line.c\
		src/raycast/new_raycast.c\
		src/raycast/new_raycast_2.c\
		src/raycast/raycast_orientation.c\
		src/raycast/raycast_collision.c\
		src/raycast/raycast_view.c\
		src/raycast/raycast_view_2.c\
		src/raycast/raycast_filtre.c\
		src/texture/infinit_join.c\
		src/texture/hand.c\
		src/texture/wall_textures.c\
		src/utils/utils_1.c\
		src/utils/utils_2.c\
		memory_manager/memory_manager.c\
		memory_manager/memory_manager_2.c\
		memory_manager/memory_manager_utils.c\
		src/parsing_map/copy_file.c\
		src/parsing_map/pars_raw_file.c\
		src/parsing_map/copy_file_utils.c\
		src/parsing_map/ft_split_modif.c\
		src/parsing_map/ft_split_modif_utils.c\
		src/parsing_map/pars_raw_file_utils.c\
		src/parsing_map/pars_raw_files_utils_2.c\
		src/parsing_map/pars_clean_map.c\
		src/parsing_map/pars_clean_map_utils.c\

OBJS	= ${SRCS:.c=.o}
OBJS_BN	= ${SRCS_BN:.c=.o}

all: gnl rprintf libmlx $(NAME)

bonus: gnl rprintf libmlx $(NAME)

gnl:
	@$(MAKE) -C $(GNL)

rprintf:
	@$(MAKE) -C $(RPTINTF)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BN)
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(RPTINTF) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(RPTINTF) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx