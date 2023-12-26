# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/12/24 21:12:47 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
NAME_BONUS		=	$(NAME)_bonus

SRC				=	colorpack/fdf_colorpack_bytes.c \
					colorpack/fdf_colorpack_int.c \
					map/fdf_map_free.c \
					map/fdf_map_parse.c \
					render/camera/fdf_camera_init.c \
					render/hud/fdf_hud_display.c \
					render/mlx/fdf_default_image.c \
					render/mlx/fdf_mlx_init.c \
					render/mlx/fdf_mlx_setup_events.c \
					render/mlx/fdf_mlx_key_pressed.c \
					render/mlx/fdf_mlx_update.c \
					render/mlx/fdf_mlx_window_event.c \
					render/vertex/fdf_vb_build.c \
					render/vertex/fdf_vb_clone.c \
					render/vertex/fdf_vb_free.c \
					vector/fdf_vec_add.c \
					vector/fdf_vec_div.c \
					vector/fdf_vec_from.c \
					vector/fdf_vec_length.c \
					vector/fdf_vec_mult.c \
					vector/fdf_vec_sub.c \
					fdf_strerror.c \
					main.c

SRC_BONUS		=	main.c

SRC_DIR			=	src
SRC_BONUS_DIR	=	src_bonus
SRC_BONUS		:= 	$(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS:.c=_bonus.c))
SRC				:=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ				= 	$(SRC:.c=.o)
OBJ_BONUS		=	$(SRC_BONUS:.c=.o)

INCLUDE_DIR		= 	include

MLX_DIR			=	MacroLibX
MLX				=	$(MLX_DIR)/libmlx.so

LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/build/output/libft.so

CC				=	clang
CFLAGS			= 	-Wall -Wextra -Werror -g3
COPTS			= 	-I $(INCLUDE_DIR) -I $(MLX_DIR)/$(INCLUDE_DIR)s -I $(LIBFT_DIR)/$(INCLUDE_DIR)

#
# Rules
#

all:			$(NAME)

$(NAME):		$(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(COPTS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) -lSDL2 -lm -fuse-ld=mold

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(LIBFT) $(MLX) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(COPTS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLX) -lSDL2 -lm -fuse-ld=mold

$(LIBFT):
	mold -run make -j -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)" all

$(MLX):
	mold -run make -j -C $(MLX_DIR) all

%.o:	%.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean:			clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all bonus libft mlx clean fclean re
