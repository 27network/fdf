# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/10/31 00:43:05 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME			=	ft
LIBSTATIC		=	lib$(LIBNAME).a
LIBSHARE		= 	lib$(LIBNAME).so
NAME			= 	$(LIBSTATIC)

BUILD_FOLDER	= 	build
OUTPUT_FOLDER	= 	$(BUILD_FOLDER)/output

SRC_FILES		=	io/ft_putchar.c \
					io/ft_putchar_fd.c \
				   	io/ft_putendl.c \
				   	io/ft_putendl_fd.c \
				   	io/ft_putnbr.c \
				   	io/ft_putnbr_fd.c \
				   	io/ft_putstr.c \
				   	io/ft_putstr_fd.c \
					list/ft_lstadd_back.c \
				   	list/ft_lstadd_front.c \
				   	list/ft_lstclear.c \
				   	list/ft_lstdelone.c \
				   	list/ft_lstiter.c \
				   	list/ft_lstlast.c \
				   	list/ft_lstmap.c \
				   	list/ft_lstnew.c \
				   	list/ft_lstsize.c \
				   	log/ft_log.c \
					log/ft_log_fd.c \
					log/ft_loglevel_name.c \
				   	mem/ft_bzero.c \
				   	mem/ft_calloc.c \
				   	mem/ft_memchr.c \
				   	mem/ft_memcmp.c \
				   	mem/ft_memcpy.c \
				   	mem/ft_memmove.c \
				   	mem/ft_memset.c \
				   	string/atox/ft_atof.c \
					string/atox/ft_atoi.c \
					string/atox/ft_atoll.c \
					string/atox/ft_atoui.c \
					string/atox/ft_atoull.c \
					string/xtoa/ft_lltoa.c \
					string/xtoa/ft_lltoa_base.c \
					string/xtoa/ft_ulltoa.c \
					string/xtoa/ft_ulltoa_base.c \
				   	string/ft_isalnum.c \
				   	string/ft_isalpha.c \
				   	string/ft_isascii.c \
				   	string/ft_isdigit.c \
				   	string/ft_isprint.c \
					string/ft_isspace.c \
					string/ft_lllen.c \
					string/ft_lllen_base.c \
				   	string/ft_split.c \
					string/ft_strall.c \
					string/ft_strany.c \
				   	string/ft_strchr.c \
					string/ft_strcmp.c \
				   	string/ft_strdup.c \
				   	string/ft_striteri.c \
				   	string/ft_strjoin.c \
				   	string/ft_strlcat.c \
				   	string/ft_strlcpy.c \
				   	string/ft_strlen.c \
				   	string/ft_strmapi.c \
				   	string/ft_strncmp.c \
				   	string/ft_strnstr.c \
				   	string/ft_strrchr.c \
					string/ft_strstr.c \
				   	string/ft_strtrim.c \
				   	string/ft_substr.c \
				   	string/ft_tolower.c \
				   	string/ft_toupper.c \
					string/ft_ulllen.c \
					string/ft_ulllen_base.c
	
SRC_FOLDER		= 	src
SRC_FILES		:= 	$(addprefix $(SRC_FOLDER)/, $(SRC_FILES))

OBJ_CACHE		= 	$(BUILD_FOLDER)/objects
OBJ				= 	$(SRC_FILES:.c=.o)
OBJ_CACHE_FILES	:=	$(addprefix $(OBJ_CACHE)/, $(OBJ))
OBJ_CACHE_DIRS	:=	$(sort $(patsubst %, %, $(dir $(OBJ_CACHE_FILES))))

INCLUDE_DIR		= 	include

CC				=	clang
CFLAGS			= 	-Wall -Wextra -Werror
COPTS			= 	-fPIC -I $(INCLUDE_DIR)

# Feature flags
ifdef FT_LOG_LEVEL
	COPTS		+= 	-DFT_LOG_LEVEL=$(FT_LOG_LEVEL)
endif

AR				= 	ar rcs
RM				= 	rm -rf

#
# Rules
#

all:			_header $(NAME) so

_header:
	@echo
	@echo libft-neo v0.2.3 by kiroussa
	@echo

$(NAME):		$(OUTPUT_FOLDER)/$(NAME)

$(OUTPUT_FOLDER)/$(NAME):	$(OBJ_CACHE_FILES) | $(OUTPUT_FOLDER)
	$(AR) $(OUTPUT_FOLDER)/$(NAME) $(OBJ_CACHE_FILES)

so:				$(LIBSHARE)

$(LIBSHARE):	$(OUTPUT_FOLDER)/$(LIBSHARE)

$(OUTPUT_FOLDER)/$(LIBSHARE):	$(OBJ_CACHE_FILES) | $(OUTPUT_FOLDER)
	$(CC) $(CFLAGS) $(COPTS) -nostartfiles -shared -o $(OUTPUT_FOLDER)/$(LIBSHARE) $(OBJ_CACHE_FILES)

$(OBJ_CACHE)/%.o:	%.c | $(OBJ_CACHE_DIRS)
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

$(OBJ_CACHE_DIRS): | $(OBJ_CACHE)
	mkdir -p $(OBJ_CACHE_DIRS)

$(OBJ_CACHE):
	mkdir -p $(OBJ_CACHE)

$(OUTPUT_FOLDER):
	mkdir -p $(OUTPUT_FOLDER)

clean:
	$(RM) $(OBJ_CACHE)

fclean:			clean
	$(RM) $(BUILD_FOLDER)

re:				fclean all

.PHONY:			all clean fclean re so
