# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 22:20:12 by sbruma            #+#    #+#              #
#    Updated: 2024/06/26 13:12:14 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g
RM				=	rm -f
AR				=	ar rcs

BLUE			= \033[0;34m
PURPLE			= \033[0;35m
WHITE			= \033[0;37m
BLACK			= \033[0;30m
CYAN			= \033[0;36m
YELLOW			= \033[0;33m
RED				= \033[0;31m
GREEN			= \033[0;32m
NC				= \033[0m

MLX42_DIR		=	MLX42
MLX42			=	$(MLX42_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT_PATH		= 	libft
LIBFT			= 	libft.a

INC				= 	inc/
SRC_DIR			= 	src/
OBJ_DIR			= 	obj/
	   
SRC 			= $(SRC_DIR)fdf.c \
				$(SRC_DIR)fdf_utils.c \
				$(SRC_DIR)init_mlx.c \
				$(SRC_DIR)init_fdf.c \
				$(SRC_DIR)window_setup.c \
				$(SRC_DIR)draw.c
		
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all : $(MLX42) $(NAME)

$(NAME) : $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	clear; \
	echo "$(RED)███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝"; \
	echo "███████╗██████╗ ███████╗"; \
	echo "██╔════╝██╔══██╗██╔════╝"; \
	echo "█████╗  ██║  ██║█████╗  "; \
	echo "██╔══╝  ██║  ██║██╔══╝  "; \
	echo "██║     ██████╔╝██║     "; \
	echo "╚═╝     ╚═════╝ ╚═╝    -sbruma"; \
	echo "███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝"; \
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PATH)/$(LIBFT) $(MLX42) -I $(INC)
	@pid=$$!; \
	sleep 1; \
	clear; \
	echo "$(YELLOW)███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝"; \
	echo "███████╗██████╗ ███████╗"; \
	echo "██╔════╝██╔══██╗██╔════╝"; \
	echo "█████╗  ██║  ██║█████╗  "; \
	echo "██╔══╝  ██║  ██║██╔══╝  "; \
	echo "██║     ██████╔╝██║     "; \
	echo "╚═╝     ╚═════╝ ╚═╝    -sbruma"; \
	echo "███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝"; \
	sleep 1; \
	clear; \
	echo "$(GREEN)███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝"; \
	echo "███████╗██████╗ ███████╗"; \
	echo "██╔════╝██╔══██╗██╔════╝"; \
	echo "█████╗  ██║  ██║█████╗  "; \
	echo "██╔══╝  ██║  ██║██╔══╝  "; \
	echo "██║     ██████╔╝██║     "; \
	echo "╚═╝     ╚═════╝ ╚═╝    -sbruma "; \
	echo "███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝"; \
	wait $$pid

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(MLX42):
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		clear; \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@cmake -B $(MLX42_DIR)/build -S $(MLX42_DIR) > /dev/null 2>&1
	@make -C $(MLX42_DIR)/build -j4 > /dev/null 2>&1

$(LIBFT_PATH)/$(LIBFT) : 
	@make -C $(LIBFT_PATH) > /dev/null 2>&1

clean :
	@$(RM) -f $(OBJ)
	@$(RM) -rf $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean > /dev/null 2>&1
	clear; \
	echo "$(CYAN)███████╗███████╗███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝"; \
	echo " ██████╗██╗     ███████╗ █████╗ ███╗   ██╗"; \
	echo "██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║"; \
	echo "██║     ██║     █████╗  ███████║██╔██╗ ██║"; \
	echo "██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║"; \
	echo "╚██████╗███████╗███████╗██║  ██║██║ ╚████║"; \
	echo "╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝"; \
	echo "███████╗███████╗███████╗███████╗███████╗███████╗"; \
	echo "╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝ $(NC)"; 

fclean : clean
	@$(RM) $(NAME)
	@$(RM) -rf $(MLX42_DIR)
	@make -C $(LIBFT_PATH) fclean > /dev/null 2>&1

re : clean fclean all
