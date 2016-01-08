# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/01/08 16:09:09 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g

SRC 		= 	ft_printf.c

LIB			=	libft.a

OBJ			=	$(SRC:.c=.o)

HEADER 		=	libft/libft.h ft_printf.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	cd libft/ && $(MAKE)
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.SILENT : clean
clean:
	cd libft/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	cd libft/ && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

