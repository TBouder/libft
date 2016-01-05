# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/01/04 11:59:53 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	ft_atoi.c ft_atoi_part.c ft_itoa.c \
				\
				ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_isnumber.c ft_isspace.c ft_isprime.c \
				ft_next_prime.c \
				\
				ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_memalloc.c ft_memdel.c \
				ft_realloc.c \
				\
				ft_nbrlen.c ft_strlen.c ft_linelen.c \
				\
				ft_strcat.c ft_strncat.c ft_strlcat.c \
				ft_strcpy.c ft_strncpy.c \
				ft_strchr.c ft_strrchr.c \
				ft_strstr.c ft_strnstr.c \
				ft_strcmp.c	ft_strncmp.c \
				ft_strdup.c \
				ft_striter.c ft_striteri.c \
				ft_strequ.c ft_strnequ.c \
				ft_strmap.c ft_strmapi.c \
				\
				ft_strnew.c ft_strdel.c ft_strclr.c \
				ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strtrim_char.c\
				ft_strsplit.c \
				ft_bzero.c ft_tolower.c ft_toupper.c \
				\
				ft_nbrsmallest.c ft_nbrlargest.c \
				\
				ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c \
				ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
				ft_nbrendl.c \
				\
				ft_lstnew.c ft_lstadd.c ft_lstclr.c ft_lstdelone.c \
				ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
				ft_lststart.c ft_lstend.c ft_lstlen.c ft_lstprint.c \
				ft_lstcontentsize.c \
				\
				ft_rand.c


OBJ			=	$(SRC:.c=.o)

HEADER 		= 	./libft.h



all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.SILENT : clean
clean:
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	rm -f $(NAME)

re: fclean all

