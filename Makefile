#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srabah <srabah@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/04 01:35:37 by srabah            #+#    #+#              #
#    Updated: 2015/02/27 23:01:21 by srabah           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = 	srcs/main.c\
		srcs/ft_fdf_1.c\
		srcs/ft_fdf_2.c\
		srcs/ft_fdf_3.c\

LIBFT_DIR = ./libft

MINILIB_DIR = ./minilibx

X11_DIR = /usr/X11/lib

SRC1 = 	srcs/main.o\
		srcs/ft_fdf_1.o\
		srcs/ft_fdf_2.o\
		srcs/ft_fdf_3.o\

FLAGS = -Wall -Werror -Wextra

MOVING = 	main.o\
			ft_fdf_1.o\
			ft_fdf_2.o\
			ft_fdf_3.o\

all		: $(NAME)

$(NAME) :
		@echo 'Processing files...'
		@gcc -c $(FLAGS) $(SRC)
		@mv $(MOVING) srcs
		@make -C $(LIBFT_DIR)
		@make -C $(MINILIB_DIR)
		@echo 'Compiling libft and minilibx'
		@gcc $(FLAGS) -L$(MINILIB_DIR) -lmlx -L$(X11_DIR) -lXext -lX11 -L$(LIBFT_DIR) -lft -o $(NAME) $(SRC1)
		@echo '$(NAME) has been created !'

clean	:
		@make -C $(LIBFT_DIR) clean
		@rm -rf $(SRC1)
		@echo 'Objects files has been removed !'

fclean : clean
		@make -C $(LIBFT_DIR) fclean
		@make -C $(MINILIB_DIR) clean
		@rm -rf $(NAME)
		@echo 'Removing $(NAME)'

re : fclean all 