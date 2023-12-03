# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/12/03 00:51:27 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
NAME_BONUS		=	$(NAME)_bonus

SRC				=	main.c
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

$(NAME):		libft mlx $(OBJ)
	$(CC) $(CFLAGS) $(COPTS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	libft mlx $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(COPTS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLX)

libft:	$(LIBFT)

$(LIBFT):
	make -j$(shell nproc) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)" all

mlx:	$(MLX)

$(MLX):
	make -j$(shell nproc) -C $(MLX_DIR) all

%.o:	%.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean:			clean
	$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all bonus libft mlx clean fclean re
