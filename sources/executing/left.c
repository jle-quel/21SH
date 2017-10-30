/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:21:39 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/30 09:40:03 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str)
{
	ft_putstr_fd("21sh: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);
	exit(EXIT_FAILURE);
}

static void		heredoc(t_ast *ast, t_line *line, t_process *process)
{
	ft_memdel((void **)&line->str);
	while (101010)
	{
		read_stdin(HEREDOC, line, process);
		if (ft_strcmp(line->str, ast->command[0]) == 0)
		{
			ft_memdel((void **)&line->str);
			break ;
		}
		ft_putendl(line->str);
		ft_memdel((void **)&line->str);
	}
}

static void		simple(t_ast *ast)
{
	int			fd;
	char		*str;

	fd = open(ast->command[0], O_RDWR);
	if (fd > 0)
	{
		while (gnl(fd, &str))
		{
			ft_putendl(str);
			ft_memdel((void **)&str);
		}
	}
	else
		error(ast->command[0]);
	close(fd);
}

static char		for_norminette(t_ast *ast, t_line *line, t_process *process,
				int *fd)
{
	ft_non_canonique();
	if (ft_strcmp(ast->operater, "<<") == 0)
	{
		write_pipe(fd);
		heredoc(ast->right, line, process);
	}
	else
	{
		write_pipe(fd);
		simple(ast->right);
	}
	exit(EXIT_SUCCESS);
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_left(t_ast *ast, t_line *line, t_process *process)
{
	int			status;
	int			fd[2];
	pid_t		father;

	if (process->forked == false)
		ft_fork(ast, line, process, &ft_left);
	else
	{
		pipe(fd);
		father = fork();
		if (father != -1)
		{
			if (father == 0)
				for_norminette(ast, line, process, fd);
			else
			{
				waitpid(father, &status, 0);
				read_pipe(fd);
				status > 0 ? exit(EXIT_FAILURE) : 0;
				executing(ast->left, line, process);
			}
		}
	}
}
