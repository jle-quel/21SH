/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:55:21 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 23:01:20 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

/*
******************* LIBRARY ****************************************************
*/

# include "../libft/includes/libft.h"

/*
******************* DEFINES ****************************************************
*/

# define RESET_STRUCT			0
# define SAVE_STRUCT			1
# define REC_STRUCT				2

# define DEFAULT				1
# define DQUOTE					2
# define QUOTE					4
# define NEXTCMD				8
# define HEREDOC				16
# define PRINT					32
# define KEY_EOF				4
# define CLEAR_KEY				12
# define DELETE_KEY				127

# define ARROW_LEFT				4479771
# define ARROW_DOWN				4348699
# define ARROW_UP				4283163
# define ARROW_RIGHT			4414235
# define END_KEY				4610843
# define HOME_KEY				4741915

# define DEL_KEY				2117294875

# define SHIFT_UP_KEY			71683997260571
# define SHIFT_DOWN_KEY			72783508888347
# define SHIFT_RIGHT_KEY		73883020516123
# define SHIFT_LEFT_KEY			74982532143899

# define HISTSIZE				500
# define PATH_HISTORY			"/.21sh_history"

# define MV_LEFT				tputs(tgetstr("le", 0), 0, &my_put)
# define MV_BOT					tputs(tgetstr("do", 0), 0, &my_put)
# define MV_TOP					tputs(tgetstr("up", 0), 0, &my_put)
# define CURSOR_INVIS			tputs(tgetstr("vi", 0), 0, &my_put)
# define CURSOR_BACK			tputs(tgetstr("ve", 0), 0, &my_put)
# define CLEAR_FROM_CUR			tputs(tgetstr("cd", 0), 0, &my_put)
# define BACK_N					tputs(tgetstr("cr", 0), 0, &my_put)

# define TOKEN 1
# define OPERATER 2
# define IO_NUMBER 3
# define PREV 0
# define NEXT 1
# define SLASH 8

# define SYNTAX_ERR 666
# define COMMAND_404 667
# define NOT_SUPPORTED 668
# define DENIED 669
# define DIRECTORY 670
# define FILE_404 671
# define EXIT_ARG 672
# define EXIT_DIGIT 673

# define PRIO_SEPARATOR 1
# define PRIO_CMD_AND_OR 2
# define PRIO_PIPE 3
# define PRIO_REDIR 4
# define PRIO_COMMAND 5

# define VALUE_COMMAND 0
# define VALUE_SEMI_COLON 1
# define VALUE_AMPERSAND 2
# define VALUE_AND_IF 3
# define VALUE_OR_IF 4
# define VALUE_PIPELINE 5
# define VALUE_LESS 6
# define VALUE_GREAT 7
# define VALUE_DLESS 8
# define VALUE_DGREAT 9
# define VALUE_GREAT_AND 10

/*
*********************** STRUCTURES *********************************************
*/

typedef struct			s_cmd
{
	char				c;
	int					value;
	struct s_cmd		*next;
	struct s_cmd		*prev;
}						t_cmd;

typedef struct			s_cursor
{
	int					line;
	int					co;
}						t_cursor;

typedef struct			s_read
{
	t_cmd				*cmd;
	t_cursor			cur;
	int					history;
	int					finish;
	int					print;
}						t_read;

typedef struct			s_cmp
{
	unsigned long		key;
	int					(*f)(struct s_read **read_std, unsigned long buff);
}						t_cmp;

typedef struct			s_hist
{
	struct s_read		*hist;
	struct s_hist		*prev;
	struct s_hist		*next;
}						t_hist;

typedef struct			s_parsing
{
	char				*input;
	int					value;
	int					priority;
	char				**command;
	struct s_parsing	*prev;
	struct s_parsing	*next;
}						t_parsing;

typedef struct			s_ast
{
	size_t				place;
	int					value;
	char				**command;
	struct s_ast		*left;
	struct s_ast		*right;
}						t_ast;

typedef struct			s_shell
{
	char				**env;
	t_parsing			*parsing;
}						t_shell;

typedef struct			s_process
{
	short				builtins;
	bool				forked;
	pid_t				process;
	uint8_t				ret;
}						t_process;

typedef struct			s_lexing
{
	char				*str;
	int					value;
	int					priority;
}						t_lexing;

typedef struct			s_error
{
	int					err_type;
	char				*str;
	int					err_ret;
}						t_error;

typedef struct			s_exec
{
	int					value;
	void				(*f)(t_ast *ast, t_shell *shell, t_process *process);
}						t_exec;

typedef struct			s_blts
{
	char				*str;
	void				(*f)(char **str, char ***env, unsigned char *ret);
}						t_blts;

char					*save_home(char *str);

/*
*********************** BUILTINS ***********************************************
*/

void					ft_echo(char **command, char ***env, uint8_t *ret);
void					ft_cd(char **command, char ***env, uint8_t *ret);
void					ft_env(char **command, char ***env, uint8_t *ret);
void					ft_exit(char **command, char ***env, uint8_t *ret);
void					ft_setenv(char **command, char ***env, uint8_t *ret);
void					ft_unsetenv(char **command, char ***env, uint8_t *ret);

/*
*********************** CORE ***************************************************
*/

t_shell					*initiate_shell(void);
t_process				*initiate_process(void);
void					lexing(t_parsing **node, t_cmd *cmd);
void					parsing(t_parsing **node, uint8_t *ret);
void					expanding(t_parsing *node, char **env);
void					populating(t_ast **ast, t_parsing *node, char **env);
void					delete(t_ast **ast, t_parsing **node, t_cmd **cmd);

/*
*********************** EXECUTING **********************************************
*/

void					executing(t_ast *ast, t_shell *shell,
						t_process *process);
void					ft_semicolon(t_ast *ast, t_shell *shell,
						t_process *process);
void					ft_and(t_ast *ast, t_shell *shell, t_process *process);
void					ft_or(t_ast *ast, t_shell *shell, t_process *process);
void					ft_pipe(t_ast *ast, t_shell *shell, t_process *process);
void					ft_left(t_ast *ast, t_shell *shell, t_process *process);
void					ft_doubleleft(t_ast *ast, t_shell *shell,
						t_process *process);
void					ft_right(t_ast *ast, t_shell *shell,
						t_process *process);
void					ft_aggre(t_ast *ast, t_shell *shell,
						t_process *process);
void					ft_fork(t_ast *ast, t_shell *shell, t_process *process,
						void (*f)(t_ast *ast, t_shell *shell,
						t_process *process));
void					ft_execve(t_ast *ast, t_shell *shell,
						t_process *process);
void					write_pipe(int *fd);
void					read_pipe(int *fd);

/*
*********************** LEXING *************************************************
*/

void					tokenisation(t_cmd *cmd);
void					lexer(t_cmd *cmd, t_parsing **node);
void					token_recognition(t_parsing *node);

/*
*********************** PARSING ************************************************
*/

void					syntax(t_parsing **node, uint8_t *ret);
void					order(t_parsing **node, uint8_t *ret);
void					empty(t_parsing **node, uint8_t *ret);

/*
*********************** EXPANDING **********************************************
*/

void					split(t_parsing *node);
void					tilde(t_parsing *node, char **env);
void					variable(t_parsing *node, char **env);
void					backslash(t_parsing *node);
size_t					split_skip(char *str);
size_t					split_getlength(char *str);
void					remove_quote(char **str);

/*
*********************** POPULATING *********************************************
*/

void					operaters(t_ast **ast, t_parsing *node, int priority);
void					commands(t_ast **ast, t_parsing *node, char **env);
void					create_access(t_parsing *node, char **env);

/*
*********************** HISTORY ************************************************
*/

void					copy_cmd(t_read **read_std, t_cmd *cpy);
t_hist					*gbl_save_history(t_hist *hist, int flags);
uint8_t					init_history(char **env);
int						make_list_hist(t_read *read_std);
t_hist					*create_hist(t_read *read_std);
void					next_history(t_read **read_std);
void					previous_history(t_read **read_std);
void					reset_history(void);
uint8_t					b_write_history_in_file(void);
t_hist					*set_history_to_last(void);

/*
*********************** PROMPT *************************************************
*/

char					*get_prompt(char **env);
char					*get_branch(char **env);
char					*create_prompt(char **env, uint8_t *ret);
void					prompt_exec(char *command[], char **env, int fd);

/*
*********************** READ ***************************************************
*/

void					init_termcap(void);
int						check_cmd(t_read **read_std);
t_cmd					*finish_read_std(t_read **read_std);
t_cmd					*first_cmd(t_cmd *cmd, int history);
t_cmd					*gbl_save_read(t_cmd *read_std);
int						get_len_prompt(int len);
t_read					*init_struct_for_read(void);
void					insert_one_line(void);
int						ft_isprint(int c);
int						ft_iscrlf(char c);
int						key_arrow_down(t_read **read_std, unsigned long buff);
int						key_arrow_up(t_read **read_std, unsigned long buff);
int						key_arrow_right(t_read **read_std, unsigned long buff);
int						key_arrow_left(t_read **read_std, unsigned long buff);
int						key_clear_(t_read **read_std, unsigned long buff);
int						key_delete_here(t_read **read_std, unsigned long buff);
int						key_del(t_read **read_std, unsigned long buff);
int						key_enter_(t_read **read_std, unsigned long buff);
int						key_eof(t_read **read_std, unsigned long buff);
int						key_end_(t_read **read_std, unsigned long buff);
int						key_home_(t_read **read_std, unsigned long buff);
int						key_print_(t_read **read_std, unsigned long *buff);
int						key_print_fct(t_cmd *cmd, char c);
t_cmd					*create_element(char c);
int						key_shift_right(t_read **read_std, unsigned long buff);
int						key_shift_left(t_read **read_std, unsigned long buff);
int						key_shift_down(t_read **read_std, unsigned long buff);
int						key_shift_up(t_read **read_std, unsigned long buff);
t_cmd					*last_cmd(t_cmd *cmd);
int						memdel_read(t_read **read_std);
int						memdel_cmd(t_cmd **cmd);
int						my_put(int c);
int						print_struct(t_read *read_std);
t_cursor				prompt(unsigned char flags, char **env,
						unsigned char *ret);
t_cmd					*read_stdin(unsigned char flags, t_shell *shell,
						t_process *process);
void					restore_cursor_(t_cursor cur);
int						signal_reception(int brk);
int						init_fd(void);
char					*handler(char *err);

/*
*********************** SIGNAL *************************************************
*/

void					ft_signal(void);

/*
*********************** TOOLS **************************************************
*/

void					lstdel(t_parsing **node);
void					lstadd(t_parsing *node, t_parsing *new);
t_parsing				*lstnew(char *input, int value, int priority,
						char **command);
void					lstnext(t_parsing **node);
void					cmddel(t_cmd **cmd);
void					error(char *str, uint8_t *ret, int err);
void					syntax_err(char *str, char *error);
void					tokenisation_logger(t_cmd *cmd, int fd);
void					list_logger(t_parsing *node);
void					split_logger(t_parsing *node, int fd);
void					ast_logger(t_ast *ast, int fd);
uint8_t					chk_quote(char c, uint8_t *status);
void					add_to_tree(t_ast **ast, size_t place, t_parsing *node);
void					treedel(t_ast **ast);
char					**get_path(char **env);
int						get_env_index(char *str, char **env);

#endif
