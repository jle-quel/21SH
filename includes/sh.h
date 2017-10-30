/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:55:21 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/30 09:58:04 by jle-quel         ###   ########.fr       */
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

# define HEREDOC				1
# define DQUOTE					2
# define QUOTE					4
# define NEXTCMD				8
# define DEFAULT				16
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

# define FD 666
# define DI 667

# define COLON 13
# define PIPE 14
# define OR 15
# define AND 16
# define LEFT 17
# define RIGHT 18
# define AGGRE 19

/*
******************* STRUCTURES *************************************************
*/

typedef struct		s_cmd
{
	char			c;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct		s_cursor
{
	int				line;
	int				co;
}					t_cursor;

typedef struct		s_read
{
	t_cmd			*cmd;
	t_cursor		cur;
	int				history;
	int				finish;
	int				print;
}					t_read;

typedef struct		s_cmp
{
	unsigned long	key;
	int				(*function)(struct s_read **read_std, unsigned long buff);
}					t_cmp;

typedef struct		s_hist
{
	struct s_read	*hist;
	struct s_hist	*prev;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_ast
{
	int				place;
	int				type;
	char			*operater;
	char			**command;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

typedef struct		s_line
{
	char			*prompt;
	char			*str;
	char			**env;
	t_list			*node;
}					t_line;

typedef struct		s_process
{
	int				logger;
	short			builtins;
	bool			forked;
	pid_t			process;
	unsigned char	ret;
}					t_process;

typedef struct		s_blts
{
	char			*str;
	void			(*f)(char **str, char ***env, unsigned char *ret);
}					t_blts;

typedef struct		s_exec
{
	int				type;
	void			(*f)(t_ast *ast, t_line *line, t_process *process);
}					t_exec;

typedef struct		s_lexer
{
	char			*str;
	int				type;
}					t_lexer;

char			*save_home(char *str);

/*
******************* BUILTINS ***************************************************
*/

void				ft_echo(char **command, char ***env, unsigned char *ret);
void				env(char **command, char ***env, unsigned char *ret);
void				exiit(char **command, char ***env, unsigned char *ret);
void				seteenv(char **command, char ***env, unsigned char *ret);
void				unseteenv(char **command, char ***env, unsigned char *ret);
void				cd(char **command, char ***env, unsigned char *ret);

/*
******************* CORE *******************************************************
*/

t_line				*initiate_line(void);
t_process			*initiate_process(void);

/*
******************* EXECUTING **************************************************
*/

void				executing(t_ast *ast, t_line *line, t_process *process);
void				ft_left(t_ast *ast, t_line *line, t_process *process);
void				colon(t_ast *ast, t_line *line, t_process *process);
void				right(t_ast *ast, t_line *line, t_process *process);
void				ft_pipe(t_ast *ast, t_line *line, t_process *process);
void				ft_and(t_ast *ast, t_line *line, t_process *process);
void				ft_or(t_ast *ast, t_line *line, t_process *process);
void				ft_aggre(t_ast *ast, t_line *line, t_process *process);

/*
******************* EXPANDING **************************************************
*/

void				iteration(t_list *node, char **env, unsigned char ret,
					void (*f)(char **str, char **env, unsigned char ret));
void				expanding_pid(char **str, char **env, unsigned char ret);
void				expanding_tilde(char **str, char **env, unsigned char ret);
void				expanding_ret(char **str, char **env, unsigned char ret);
void				expanding_var(char **str, char **env, unsigned char ret);
void				expanding_quote(char **str, char **env, unsigned char ret);
void				expanding_backslash(char **str, char **env,
					unsigned char ret);

/*
******************* HISTORY ****************************************************
*/

void				copy_cmd(t_read **read_std, t_cmd *cpy);
t_hist				*gbl_save_history(t_hist *hist, int flags);
uint8_t				init_history(char **env);
int					make_list_hist(t_read *read_std);
t_hist				*create_hist(t_read *read_std);
void				next_history(t_read **read_std);
void				previous_history(t_read **read_std);
void				reset_history(void);
uint8_t				b_write_history_in_file(void);
t_hist				*set_history_to_last(void);

/*
******************* PARSING ****************************************************
*/

void				trim_str(char **str);
void				parsing_str(char **str, unsigned char *ret);
void				lexing(t_list **node, char *str);
void				trim_beginning(t_list **node, unsigned char *ret);
void				trim_last(t_list **node, unsigned char *ret);
void				parsing_operaters(t_list **node, unsigned char *ret);
void				parsing_words(t_list **node, unsigned char *ret);
void				parsing_stds(t_list *node);
void				parsing_redirections(t_list **node);

/*
******************* POPULATING *************************************************
*/

void				bonus_tokens(t_ast **ast, int place, t_list *node,
					char *ope);
void				second_tokens(t_ast **ast, int place, t_list *node,
					char *ope);
void				primary_tokens(t_ast **ast, int place, t_list *node,
					char *ope);
void				operaters(t_ast **ast, t_list *node, char *ope,
					void (*f)(t_ast **ast, int place, t_list *node, char *ope));
void				add_to_tree(t_ast **ast, int place, t_list *node,
					char **command);
char				**split(char *str);
void				commands(t_ast **ast, t_list *node, char **env);
void				ft_treedel(t_ast **node);
char				**get_path(char **env);

/*
******************* PROMPT *****************************************************
*/

char				*get_prompt(char **env);
char				*get_branch(char **env);
char				*create_prompt(char **env, unsigned char *ret);

/*
******************* READ *******************************************************
*/

int					check_cmd(t_read **read_std);
char				*finish_read_std(t_read **read_std);
t_cmd				*first_cmd(t_cmd *cmd, int history);
t_cmd				*gbl_save_read(t_cmd *read_std);
int					get_len_prompt(int len);
t_read				*init_struct_for_read(void);
void				insert_one_line(void);
int					ft_isprint(int c);
int					ft_iscrlf(char c);
int					key_arrow_down(t_read **read_std, unsigned long buff);
int					key_arrow_up(t_read **read_std, unsigned long buff);
int					key_arrow_right(t_read **read_std, unsigned long buff);
int					key_arrow_left(t_read **read_std, unsigned long buff);
int					key_clear_(t_read **read_std, unsigned long buff);
int					key_delete_here(t_read **read_std, unsigned long buff);
void				delete_here(t_read **read_std);
int					key_del(t_read **read_std, unsigned long buff);
int					key_enter_(t_read **read_std, unsigned long buff);
int					key_eof(t_read **read_std, unsigned long buff);
int					key_end_(t_read **read_std, unsigned long buff);
int					key_home_(t_read **read_std, unsigned long buff);
int					key_print_(t_read **read_std, unsigned long *buff);
int					key_print_fct(t_cmd *cmd, char c);
t_cmd				*create_element(char c);
int					key_shift_right(t_read **read_std, unsigned long buff);
int					key_shift_left(t_read **read_std, unsigned long buff);
int					key_shift_down(t_read **read_std, unsigned long buff);
int					key_shift_up(t_read **read_std, unsigned long buff);
t_cmd				*last_cmd(t_cmd *cmd);
int					memdel_read(t_read **read_std);
int					memdel_cmd(t_cmd **cmd);
int					my_put(int c);
int					print_struct(t_read *read_std);
t_cursor			prompt(unsigned char flags, char **env, unsigned char *ret);
void				read_stdin(unsigned char flags, t_line *line,
					t_process *process);
void				restore_cursor_(t_cursor cur);
int					signal_reception(int brk);
int					init_fd(void);

/*
******************* SIGNAL *****************************************************
*/

void				ft_signal(void);

/*
******************* TOOLS ******************************************************
*/

bool				chk_operaters(char c);
bool				chk_slash(const char *str, size_t index);
void				chk_quotes(char c, char quote, const int *flag, int *value);
int					get_env_index(char *str, char **env);
void				ft_execve(t_ast *ast, t_line *line, t_process *process);
void				read_pipe(int *fd);
void				write_pipe(int *fd);
void				ft_fork(t_ast *ast, t_line *line, t_process *process,
					void (*f)(t_ast *ast, t_line *line, t_process *process));
void				init_termcap(void);
void				ft_non_canonique(void);
void				ft_canonique(void);
void				remove_quote(char **str);
char				*handler(char *err);
void				skip_quote(char *str, size_t *index, char c);
void				do_skip(char *str, size_t *index);
void				prompt_exec(char *command[], char **env, int fd);
size_t				get_length_redirection(char *str, unsigned int index, char c);
bool				chk_redirection(char c);

#endif
