/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:40:16 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 18:47:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static bool		lstcmp(t_cmd *cmd, char *str)
{
	while (cmd && cmd->c && *str)
	{
		if (cmd->c != *str)
			return (false);
		cmd = cmd->next;
		str++;
	}
	return (true);
}

static void		printcmd(t_cmd *cmd)
{
	while (cmd && cmd->c)
	{
		ft_putchar(cmd->c);
		cmd = cmd->next;
	}
	ft_putchar(10);
}

/*
*************** PRIVATE ********************************************************
*/

static void		heredoc(t_ast *ast, t_shell *shell, t_process *process)
{
	t_cmd		*cmd;

	while (101010)
	{
		cmd = read_stdin(HEREDOC, shell, process);
		if (cmd)
		{
			if (lstcmp(cmd, ast->command[0]))
			{
				cmddel(&cmd);
				break ;
			}
			printcmd(cmd);
			cmddel(&cmd);
		}
	}
	exit(EXIT_SUCCESS);
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_doubleleft(t_ast *ast, t_shell *shell, t_process *process)
{
	int			status;
	int			fd[2];
	pid_t		father;

	if (process->forked == false)
		ft_fork(ast, shell, process, &ft_doubleleft);
	else
	{
		pipe(fd);
		father = fork();
		if (father == 0)
		{
			write_pipe(fd);
			heredoc(ast->right, shell, process);
		}
		else
		{
			waitpid(father, &status, 0);
			read_pipe(fd);
			status > 0 ? exit(EXIT_FAILURE) : 0;
			executing(ast->left, shell, process);
		}
	}
}
