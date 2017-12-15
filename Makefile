# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/02 12:01:32 by jle-quel          #+#    #+#              #
#    Updated: 2017/11/06 23:00:33 by jle-quel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

FLAGS += -Wall -Wextra -Werror -I includes

SANITIZE += -g3 -fsanitize=address

SRC =	sources/builtins/echo.c					\
		sources/builtins/env.c					\
		sources/builtins/exit.c					\
		sources/builtins/cd.c					\
		sources/builtins/setenv.c				\
		sources/builtins/unsetenv.c				\
												\
		sources/core/main.c						\
		sources/core/core.c						\
		sources/core/initiate.c					\
												\
		sources/executing/executing.c			\
		sources/executing/semicolon.c			\
		sources/executing/and.c					\
		sources/executing/or.c					\
		sources/executing/pipe.c				\
		sources/executing/left.c				\
		sources/executing/doubleleft.c			\
		sources/executing/right.c				\
		sources/executing/aggregater.c			\
		sources/executing/tools.c				\
												\
		sources/expanding/split.c				\
		sources/expanding/tilde.c				\
		sources/expanding/variable.c			\
		sources/expanding/backslash.c			\
		sources/expanding/tools.c				\
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
		sources/lexing/tokenisation.c			\
		sources/lexing/lexer.c					\
		sources/lexing/token_recognition.c		\
												\
		sources/parsing/parsing.c				\
												\
		sources/populating/populating.c			\
		sources/populating/access.c				\
												\
        sources/prompt/create.c                 \
        sources/prompt/branch.c                 \
        sources/prompt/prompt.c                 \
		sources/prompt/tools.c					\
                                                \
		sources/read/termcap.c					\
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
		sources/tools/list.c					\
		sources/tools/error.c					\
		sources/tools/parsing.c					\
		sources/tools/tree.c					\
		sources/tools/env.c						\

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@clang -c $(FLAGS) $< -o $@

$(LIBLOG):
	@make -C logger

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@clang $(OBJ) $(FLAGS) $(LIBFT) $(LOGGER) -ltermcap -o $(NAME)

fs: $(LIBFT) $(OBJ)
	@clang $(OBJ) $(FLAGS) $(SANITIZE) $(LIBFT) $(LOGGER) -ltermcap -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean
	@make
