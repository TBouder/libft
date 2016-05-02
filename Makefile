# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/05/02 14:57:23 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

HEADER 		= 	./libft.h ./get_next_line/get_next_line.h
FT_IS		= 	$(wildcard ft_is/*.c)
FT_LEN		= 	$(wildcard ft_len/*.c)
FT_LST		= 	$(wildcard ft_lst/*.c)
FT_MEM		= 	$(wildcard ft_mem/*.c)
FT_NB		= 	$(wildcard ft_nb/*.c)
FT_PRINT	= 	$(wildcard ft_print/*.c)
FT_STR		= 	$(wildcard ft_str/*.c)
FT_DBSTR		= 	$(wildcard ft_dbstr/*.c)
FT_MATH		= 	$(wildcard ft_math/*.c)
GNL			= 	$(wildcard get_next_line/*.c)

SRC			=	$(FT_IS) $(FT_LEN) $(FT_LST) $(FT_MEM) $(FT_NB) $(FT_PRINT) \
				$(FT_STR) $(FT_DBSTR) $(FT_MATH) $(GNL)
OBJ			=	$(notdir $(SRC:.c=.o))
JUNCK		=	$(wildcard *.gch .DS_Store */.DS_Store)

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.SILENT : clean
clean:
	rm -f $(OBJ) $(JUNCK)

.SILENT : fclean
fclean: clean
	rm -f $(NAME)

re: fclean all
