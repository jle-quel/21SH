/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:43:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:20:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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

void			ft_execve(t_ast *ast, t_shell *shell, t_process *process)
{
	struct stat	buffer;

	if (process->forked == false)
		ft_fork(ast, shell, process, &ft_execve);
	else
	{
		execve(ast->command[0], ast->command, shell->env);
		lstat(ast->command[0], &buffer);
		if (S_ISDIR(buffer.st_mode))
			error(ast->command[0], &(process->ret), DIRECTORY);
		else if (!access(ast->command[0], F_OK) &&
											access(ast->command[0], X_OK) == -1)
			error(ast->command[0], &(process->ret), DENIED);
		else
			error(ast->command[0], &(process->ret), COMMAND_404);
		exit(EXIT_FAILURE);
	}
}

void			ft_fork(t_ast *ast, t_shell *shell, t_process *process,
				void (*f)(t_ast *ast, t_shell *shell, t_process *process))
{
	int			status;
	pid_t		father;

	father = fork();
	if (father != -1)
	{
		process->forked = true;
		if (father == 0)
			f(ast, shell, process);
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
