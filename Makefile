# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/02/21 00:21:21 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

FT_IS		=	ft_is/ft_isalnum.c ft_is/ft_isalpha.c ft_is/ft_isascii.c \
				ft_is/ft_isdigit.c ft_is/ft_isprint.c ft_is/ft_isnumber.c \
				ft_is/ft_isspace.c ft_is/ft_isprime.c ft_is/ft_ishexa.c

FT_LEN		=	ft_len/ft_nbrlen.c ft_len/ft_strlen.c ft_len/ft_linelen.c \
				ft_len/ft_hexalen.c

FT_LST		=	ft_lst/ft_lstnew.c ft_lst/ft_lstadd.c ft_lst/ft_lstclr.c \
				ft_lst/ft_lstdelone.c ft_lst/ft_lstdel.c ft_lst/ft_lstiter.c \
				ft_lst/ft_lstmap.c ft_lst/ft_lstnew.c ft_lst/ft_lststart.c \
				ft_lst/ft_lstend.c ft_lst/ft_lstlen.c ft_lst/ft_lstprint.c \
				ft_lst/ft_lstcontentsize.c ft_lst/ft_lsttostr.c

FT_MEM		=	ft_mem/ft_memccpy.c ft_mem/ft_memchr.c ft_mem/ft_memcmp.c \
				ft_mem/ft_memcpy.c ft_mem/ft_memmove.c ft_mem/ft_memset.c \
				ft_mem/ft_memalloc.c ft_mem/ft_memdel.c ft_mem/ft_bzero.c \
				ft_mem/ft_realloc.c

FT_NB		=	ft_nb/ft_atoi.c ft_nb/ft_atoi_part.c  ft_nb/ft_atoi_hexa.c \
				ft_nb/ft_nbrsmallest.c ft_nb/ft_nbrlargest.c \
				ft_nb/ft_next_prime.c ft_nb/ft_nbrnew.c

FT_PRINT	=	ft_print/ft_putchar.c ft_print/ft_putchar_fd.c \
				ft_print/ft_putstr.c ft_print/ft_putstr_fd.c \
				ft_print/ft_putendl.c ft_print/ft_putendl_fd.c \
				ft_print/ft_putnbr.c ft_print/ft_putnbr_base.c \
				ft_print/ft_putnbr_fd.c ft_print/ft_nbrendl.c

FT_STR		=	ft_str/ft_itoa.c ft_str/ft_itoa_base.c \
				ft_str/ft_strcat.c ft_str/ft_strncat.c ft_str/ft_strlcat.c \
				ft_str/ft_strcpy.c ft_str/ft_strncpy.c \
				ft_str/ft_strchr.c ft_str/ft_strrchr.c \
				ft_str/ft_strstr.c ft_str/ft_strnstr.c \
				ft_str/ft_strcmp.c	ft_str/ft_strncmp.c \
				ft_str/ft_strdup.c \
				ft_str/ft_striter.c ft_str/ft_striteri.c \
				ft_str/ft_strequ.c ft_str/ft_strnequ.c \
				ft_str/ft_strmap.c ft_str/ft_strmapi.c \
				ft_str/ft_strnew.c ft_str/ft_strdel.c ft_str/ft_strclr.c \
				ft_str/ft_strsub.c ft_str/ft_strjoin.c \
				ft_str/ft_strtrim.c ft_str/ft_strtrim_char.c\
				ft_str/ft_strsplit.c \
				ft_str/ft_tolower.c ft_str/ft_toupper.c

FT_MATH		=	ft_math/ft_factorial.c ft_math/ft_fibonacci.c \
				ft_math/ft_power.c ft_math/ft_sqrt.c ft_math/ft_rand.c \
				ft_math/ft_sin.c ft_math/ft_cos.c ft_math/ft_tan.c

GNL			=	get_next_line/get_next_line.c

OBJ			=	$(FT_IS:.c=.o) $(FT_LEN:.c=.o) $(FT_LST:.c=.o) \
				$(FT_MEM:.c=.o) $(FT_NB:.c=.o) $(FT_PRINT:.c=.o) \
				$(FT_STR:.c=.o) $(FT_MATH:.c=.o) $(GNL:.c=.o)

HEADER 		= 	./libft.h ./get_next_line/get_next_line.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_IS)
	mv *.o ft_is/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_LEN)
	mv *.o ft_len/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_LST)
	mv *.o ft_lst/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_MEM)
	mv *.o ft_mem/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_NB)
	mv *.o ft_nb/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_PRINT)
	mv *.o ft_print/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_STR)
	mv *.o ft_str/
	$(CC) $(CFLAGS) -c $(HEADER) $(FT_MATH)
	mv *.o ft_math/
	$(CC) $(CFLAGS) -c $(HEADER) $(GNL)
	mv *.o get_next_line/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.SILENT : clean
clean:
	rm -f $(OBJ)
	rm -f *.gch
	rm -f .DS_Store
	rm -f */.DS_Store

.SILENT : fclean
fclean: clean
	rm -f $(NAME)

re: fclean all

