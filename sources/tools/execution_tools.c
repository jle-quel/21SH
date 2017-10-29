/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:10:46 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:38:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str, char *err)
{
	ft_putstr_fd("21sh: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(err, 2);
}

/*
*************** PUBLIC *********************************************************
*/

void			read_pipe(int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void			write_pipe(int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void			ft_execve(t_ast *ast, t_line *line, t_process *process)
{
	struct stat	buffer;

	if (process->forked == false)
		ft_fork(ast, line, process, &ft_execve);
	else
	{
		execve(ast->command[0], ast->command, line->env);
		lstat(ast->command[0], &buffer);
		if (S_ISDIR(buffer.st_mode))
			error(ast->command[0], ": is a directory");
		else if (!access(ast->command[0], F_OK) &&
											access(ast->command[0], X_OK) == -1)
			error(ast->command[0], ": permission denied");
		else
			error(ast->command[0], ": command not found");
		exit(EXIT_FAILURE);
	}
}

void			ft_fork(t_ast *ast, t_line *line, t_process *process,
				void (*f)(t_ast *ast, t_line *line, t_process *process))
{
	int			status;
	pid_t		father;

	father = fork();
	if (father != -1)
	{
		process->forked = true;
		if (father == 0)
			f(ast, line, process);
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				process->ret = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				process->ret = WTERMSIG(status) + 128;
			else
				process->ret = 0;
		}
	}
	process->forked = false;
}
