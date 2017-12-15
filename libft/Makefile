# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 09:11:48 by jle-quel          #+#    #+#              #
#    Updated: 2017/10/30 20:03:35 by jle-quel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2 -I includes

OBJ = $(SRC:.c=.o)

SRC = 	sources/allocation/gnl.c				\
		sources/allocation/ft_memalloc.c		\
		sources/allocation/ft_arraydup.c		\
		sources/allocation/ft_strdup.c		    \
		sources/allocation/get_next_line.c		\
		sources/allocation/ft_strsub.c		    \
		sources/allocation/ft_strjoin.c		    \
		sources/allocation/ft_strsplit.c		\
		sources/allocation/ft_itoa.c		    \
		sources/allocation/ft_threejoin.c		\
		sources/allocation/ft_arrayjoin.c		\
		sources/allocation/ft_strtrim.c			\
		sources/allocation/ft_newstr.c			\
												\
		sources/delete/ft_memdel.c				\
		sources/delete/ft_arraydel.c			\
												\
		sources/length/ft_strlen.c				\
		sources/length/ft_arraylen.c			\
		sources/length/ft_lstlen.c				\
		sources/length/ft_strrlen.c				\
		sources/length/ft_intlen.c				\
												\
		sources/list/ft_lstnew.c                \
		sources/list/ft_lstadd.c                \
		sources/list/ft_lstdel.c	    		\
		sources/list/ft_ptrnext.c	    		\
		sources/list/ft_ptrprev.c	    		\
												\
		sources/print/ft_putbnr.c				\
		sources/print/ft_putbnr_fd.c			\
		sources/print/ft_putchar.c				\
		sources/print/ft_putchar_fd.c			\
		sources/print/ft_putendl.c				\
		sources/print/ft_putendl_fd.c			\
		sources/print/ft_putlst.c				\
		sources/print/ft_putlst_fd.c			\
		sources/print/ft_putnbr.c				\
		sources/print/ft_putnbr_fd.c			\
		sources/print/ft_putstr.c				\
		sources/print/ft_putstr_fd.c			\
		sources/print/ft_putarray.c				\
		sources/print/ft_putarray_fd.c			\
												\
		sources/str/ft_strncat.c				\
		sources/str/ft_strncpy.c				\
		sources/str/ft_strcat.c			    	\
		sources/str/ft_strcpy.c			    	\
		sources/str/ft_strchr.c			        \
		sources/str/ft_strlchr.c                \
		sources/str/ft_strnstr.c				\
		sources/str/ft_strstr.c					\
												\
		sources/tools/ft_strcmp.c               \
		sources/tools/ft_strncmp.c              \
		sources/tools/ft_isdigit.c              \
		sources/tools/ft_getenv.c               \
		sources/tools/ft_occurence.c            \
		sources/tools/ft_atoi.c                 \
		sources/tools/ft_strdigit.c             \
		sources/tools/ft_termcap.c              \
		sources/tools/ft_stronly.c              \
		sources/tools/ft_canonique.c            \
		sources/tools/ft_non_canonique.c        \
		sources/tools/ft_init_termcap.c         \
		sources/tools/ft_isalpha.c  	        \

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@find '.' -type f -name '*.o' -delete

fclean: clean
	@/bin/rm -Rf $(NAME)

re: fclean
	@make
