# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 13:49:23 by ymirna            #+#    #+#              #
#    Updated: 2022/06/02 16:33:43 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

PATH_M		=	game/

PATH_B		=	bonus/

PATH_H		=	headers/

SRC_M		=	main.c functs.c functs_2.c fin_game.c start.c get_next_line.c get_next_line_utils.c \
				moves.c ft_itoa.c

SRC_B		= 	main_bonus.c functs_bonus.c functs_2_bonus.c fin_game_bonus.c start_bonus.c start_2_bonus.c start_3_bonus.c\
				get_next_line_bonus.c get_next_line_utils_bonus.c moves_bonus.c ft_itoa_bonus.c

HEADER		=	so_long.h so_long_bonus.h get_next_line.h

SRC_M_P		=	$(addprefix $(PATH_M), $(SRC_M))

SRC_B_P		=	$(addprefix $(PATH_B), $(SRC_B))

HEADER_P	=	$(addprefix $(PATH_H), $(HEADER))

OBJS_M		=	$(SRC_M_P:%.c=%.o)

OBJS_B		=	$(SRC_B_P:%.c=%.o)

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra

LMLX		=	-lmlx -framework OpenGL -framework AppKit

.PHONY:		all bonus re clean fclean

%.o : %.c	$(HEADER_P)
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS_M) Makefile
			$(CC) $(FLAGS) $(OBJS_M) $(LMLX) -o $(NAME)

bonus:		
			@make OBJS_M="$(OBJS_B)" all

clean:		
			rm -f $(OBJS_M)
			rm -f $(OBJS_B)

fclean:		clean
			rm -f $(NAME)

re:			fclean all