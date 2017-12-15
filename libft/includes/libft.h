/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 06:35:48 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/30 20:03:21 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
******************* INCLUDES ***************************************************
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <stdint.h>
# include <limits.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/ioctl.h>

/*
******************* DEFINES ****************************************************
*/

# define BUFF_SIZE 42
# define N __attribute__((unused))

/*
******************* STRUCTURES *************************************************
*/

typedef struct		s_list
{
	char			*str;
	char			**argv;
	size_t			nb;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*
******************* ALLOCATION *************************************************
*/

int					gnl(int fd, char **line);
int					get_next_line(int fd, char **line);
void				*ft_memalloc(size_t size);
char				**ft_arraydup(const char **argv);
char				*ft_strdup(const char *str);
char				*ft_strsub(const char *str, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_threejoin(char *s1, char *separator, char *s2);
char				**ft_arrayjoin(const char **a1, const char **a2);
char				*ft_strtrim(char *str);
void				ft_newstr(char **str, char c);

/*
******************* DELETE *****************************************************
*/

void				ft_memdel(void **ap);
void				ft_arraydel(char ***argv);
void				ft_lstdel(t_list **alst);

/*
******************* LENGTH *****************************************************
*/

size_t				ft_strlen(const char *str);
size_t				ft_arraylen(const char **argv);
size_t				ft_lstlen(t_list *node);
size_t				ft_strrlen(const char *str, char c, size_t index);
size_t				ft_intlen(int number);

/*
******************* LIST *******************************************************
*/

void				ft_lstnew(t_list **node, const char *str,
					const char **argv, size_t number);
void				ft_lstadd(t_list *node, t_list *new);
void				ft_ptrnext(t_list **node, size_t stop);
void				ft_ptrprev(t_list **node, size_t stop);

/*
******************* PRINT ******************************************************
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putbnr(int nb);
void				ft_putbnr_fd(int nb, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putlst(t_list *node);
void				ft_putlst_fd(t_list *node, int fd);
void				ft_putarray(const char **argv);
void				ft_putarray_fd(const char **argv, int fd);

/*
******************* STR ********************************************************
*/

char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strlchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strstr(const char *big, const char *little);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
******************* TOOLS ******************************************************
*/

int					ft_isdigit(int c);
char				*ft_getenv(char **env, char *variable);
size_t				ft_occurence(char *str, char c);
int					ft_atoi(const char *str);
bool				ft_strdigit(char *str);
int					ft_termcap(char *str, int fd);
bool				ft_stronly(char *str, char c);
void				ft_canonique(void);
void				ft_non_canonique(void);
void				ft_init_termcap(void);
int					ft_isalpha(int c);

#endif
