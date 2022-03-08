# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 21:14:39 by cgregory          #+#    #+#              #
#    Updated: 2022/03/05 21:26:56 by cgregory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol
NAME_BONUS		=	./src_bonus/fractol_bonus
LIBFT_NAME		=	libft.a
SRCS_DIR		=	./src_main/
SRCS_DIR_BONUS	=	./src_bonus/
SRCS			=	main.c			messages.c\
					aux_funcs.c		hooks.c\
					draw_funcs.c	color.c\
					init.c
SRCS_BONUS		=	main.c			messages.c\
					aux_funcs.c		hooks.c\
					draw_funcs.c	color.c\
					init.c			fractol_funcs.c
LIBFT			=	libft.h
LIBFT_DIR		=	./libft/
FRACTOL_H		=	fractol.h
BONUS_H			=	fractol_bonus.h
HEADERS			=	./inc/
OBJ				=	$(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))
OBJ_BONUS		=	$(addprefix $(SRCS_DIR_BONUS), $(SRCS_BONUS:%.c=%.o))
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
.PHONY			:	all clean fclean re bonus
all				:	$(LIBFT_NAME) $(NAME)
bonus			:	$(LIBFT_NAME) $(NAME_BONUS)
$(LIBFT_NAME)	:	
					@echo "check_libft"
					make -C $(LIBFT_DIR)
$(NAME)			:	$(OBJ) $(LIBFT_DIR)$(LIBFT_NAME) $(HEADERS)$(FRACTOL_H)
					rm -rf $(OBJ_BONUS)
					$(CC) $(OBJ) $(LIBFT_DIR)$(LIBFT_NAME)\
					-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(NAME_BONUS)	:	$(OBJ_BONUS) $(LIBFT_DIR)$(LIBFT_NAME) $(HEADERS)$(BONUS_H)
					rm -rf $(OBJ)
					$(CC) $(OBJ_BONUS) $(LIBFT_DIR)$(LIBFT_NAME)\
					-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
					touch $(NAME_BONUS)
%.o:				%.c $(HEADERS)$(FRACTOL_H) $(HEADERS)$(BONUS_H)
					$(CC) $(CFLAGS) -I$(HEADERS) -I$(LIBFT_DIR)\
					-I/usr/include -Imlx_linux -O3 -c $< -o $@
clean			:	
					rm -rf $(OBJ)
					rm -rf $(OBJ_BONUS)
					make clean -C $(LIBFT_DIR)
fclean			:	clean
					rm -f $(NAME)
					rm -f $(NAME_BONUS)
					make fclean -C $(LIBFT_DIR)
re				:	fclean all
