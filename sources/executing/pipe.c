/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:51:36 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:57:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_pipe(t_ast *ast, t_line *line, t_process *process)
{
	int			fd[2];
	pid_t		father;

	if (process->forked == false)
		ft_fork(ast, line, process, &ft_pipe);
	else
	{
		pipe(fd);
		father = fork();
		if (father != -1)
		{
			if (father == 0)
			{
				read_pipe(fd);
				executing(ast->right, line, process);
			}
			else
			{
				write_pipe(fd);
				executing(ast->left, line, process);
			}
		}
	}
}
