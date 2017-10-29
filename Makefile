# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/02 12:01:32 by jle-quel          #+#    #+#              #
#    Updated: 2017/10/29 14:40:54 by jle-quel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

FLAGS += -Wall -Wextra -Werror -O2 -I includes

SRC =	sources/builtins/echo.c                 \
        sources/builtins/env.c                  \
        sources/builtins/exit.c                 \
        sources/builtins/setenv.c               \
        sources/builtins/unsetenv.c             \
        sources/builtins/cd.c                   \
                                                \
        sources/core/main.c	                    \
        sources/core/initiate.c                 \
                                                \
        sources/executing/executing.c           \
        sources/executing/left.c  		        \
        sources/executing/right.c  		        \
        sources/executing/colon.c  		        \
        sources/executing/pipe.c  		        \
        sources/executing/ft_and.c  	        \
        sources/executing/ft_or.c  	            \
        sources/executing/ft_aggre.c  	        \
												\
		sources/expanding/tilde.c				\
		sources/expanding/pid.c					\
		sources/expanding/return.c				\
		sources/expanding/variable.c			\
		sources/expanding/quote.c				\
		sources/expanding/backslash.c			\
												\
		sources/history/copy_cmd.c				\
		sources/history/gbl_save_history.c		\
		sources/history/init_history.c			\
		sources/history/make_list_hist.c		\
		sources/history/next_history.c			\
		sources/history/previous_history.c		\
		sources/history/reset_history.c			\
		sources/history/write_history.c			\
												\
	    sources/parsing/lexing.c                \
	    sources/parsing/trim_str.c              \
	    sources/parsing/parsing_str.c           \
        sources/parsing/parsing_operaters.c     \
        sources/parsing/parsing_words.c         \
        sources/parsing/parsing_stds.c          \
        sources/parsing/parsing_redirections.c  \
												\
		sources/populating/operaters.c          \
		sources/populating/commands.c           \
		sources/populating/split.c              \
												\
        sources/prompt/create.c                 \
        sources/prompt/branch.c                 \
        sources/prompt/prompt.c                 \
                                                \
		sources/read/check_cmd.c				\
		sources/read/init_fd.c					\
		sources/read/finish_read_std.c			\
		sources/read/first_cmd.c				\
		sources/read/gbl_save_read.c			\
		sources/read/get_len_prompt.c			\
		sources/read/init_struct_for_read.c		\
		sources/read/insert_one_line.c			\
		sources/read/is.c						\
		sources/read/key_arrow.c				\
		sources/read/key_clear.c				\
		sources/read/key_delete_here.c			\
		sources/read/key_delete.c				\
		sources/read/key_enter.c				\
		sources/read/key_eof.c					\
		sources/read/key_home_end.c				\
		sources/read/key_print.c				\
		sources/read/key_shift.c				\
		sources/read/last_cmd.c					\
		sources/read/memdel_read.c				\
		sources/read/my_prompt.c				\
		sources/read/my_put.c					\
		sources/read/print_struct.c				\
		sources/read/prompt.c					\
		sources/read/read_stdin.c				\
		sources/read/restore_cursor.c			\
		sources/read/signal_reception.c			\
												\
		sources/signal/signal.c					\
												\
        sources/tools/parsing_tools.c           \
        sources/tools/env_tools.c               \
        sources/tools/ast_tools.c               \
        sources/tools/execution_tools.c         \
        sources/tools/termcap_tools.c 	        \
        sources/tools/remove_quote.c 	        \
        sources/tools/split_tools.c 	        \
		sources/tools/tools.c 			        \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(FLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -ltermcap -o $(NAME)
	@echo "\033[32mCompiled Executable From 21sh\033[0m"

fs:
	gcc $(FLAGS) -g3 -fsanitize=address -L libft -lft $(OBJ) -ltermcap -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files From 21sh\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable From 21sh\033[0m"

re: fclean
	@make
