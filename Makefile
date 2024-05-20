# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 22:20:12 by sbruma            #+#    #+#              #
#    Updated: 2024/05/20 22:32:01 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar rcs

MLX42			=	MLX42/build/libmlx42.a
LIBFT_PATH		= 	libft
LIBFT			= 	libft.a

INC				= 	inc/
SRC_DIR			= 	src/
OBJ_DIR			= 	obj/

PR_DIR = $(SRC_DIR)parse/parse.c\
		   
SRC = $(PR_DIR) $(SRC_DIR)main.c
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all : $(MLX) $(NAME)

$(NAME) : $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PATH)/$(LIBFT)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(MLX42):
	@echo "Downloading MLX42"
	@git clone https://github.com/codam-coding-college/MLX42.git > /dev/null
	@cmake -B MLX42/build -S MLX42 > /dev/null && make -C MLX42/build -j4 > /dev/null
	@echo "MLX42 downloaded"

$(LIBFT_PATH)/$(LIBFT) : 
	@make -C $(LIBFT_PATH)

clean :
	@$(RM) -f $(OBJ)
	@$(RM) -rf $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@$(RM) -f $(NAME) $(MLX42)
	@make -C $(LIBFT_PATH) fclean

re : clean fclean all
