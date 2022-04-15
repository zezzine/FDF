# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 16:58:04 by zezzine           #+#    #+#              #
#    Updated: 2022/04/15 16:58:05 by zezzine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS = fdf_bonus

FLAGS = -Wall -Wextra -Werror -c

LINKER = -lmlx -framework OpenGL -framework AppKit

HEADER = fdf.h

M_SRC = ./src/main.c					\
		./src/error.c					\
		./src/read_map.c				\
		./src/get_next_line.c			\
		./src/draw_map.c				\
		./src/get_next_line_utils.c	\
		./src/events_bonus.c			\
		./src/tools.c					\
		./src/esc.c					\
		./src/ft_atoi.c				\
		./src/ft_strncmp.c			\
		./src/ft_split.c				\
		./src/ft_strrchr.c

M_OBJ = main.o					\
		error.o					\
		read_map.o				\
		get_next_line.o			\
		draw_map.o				\
		get_next_line_utils.o	\
		tools.o					\
		esc.o					\
		events_bonus.o			\
		ft_atoi.o				\
		ft_strncmp.o			\
		ft_split.o				\
		ft_strrchr.o

B_SRC = ./src/main.c					\
		./src/error.c					\
		./src/read_map.c				\
		./src/get_next_line.c			\
		./src/get_next_line_utils.c	\
		./src/draw_map.c				\
		./src/events_bonus.c			\
		./src/esc.c					\
		./src/tools.c					\
		./src/ft_atoi.c				\
		./src/ft_strncmp.c			\
		./src/ft_split.c				\
		./src/ft_strrchr.c

B_OBJ = main.o					\
		error.o					\
		read_map.o				\
		get_next_line.o			\
		draw_map.o				\
		get_next_line_utils.o	\
		events_bonus.o			\
		esc.o					\
		tools.o					\
		ft_atoi.o				\
		ft_strncmp.o			\
		ft_split.o				\
		ft_strrchr.o

all : $(NAME)

$(NAME): $(M_SRC)
		@gcc $(FLAGS) $(M_SRC) -I $(HEADER)
		@gcc $(M_OBJ) $(LINKER) -o $(NAME)
		@echo "Make mandatory part"

bonus : $(BONUS)

$(BONUS):
			@gcc $(FLAGS) $(B_SRC) -I $(HEADER)
			@gcc $(B_OBJ) $(LINKER) -o $(BONUS)
			@echo "Make bonus part"

clean :
	rm -f $(M_OBJ) $(B_OBJ)
		@echo "Delete object files" 

fclean :
	rm -f $(M_OBJ) $(NAME) $(B_OBJ) $(BONUS)

re : fclean all

.PHONUS : bonus all re fclean clean