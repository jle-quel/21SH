/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:08:27 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 23:01:44 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_pipe(t_ast *ast, t_shell *shell, t_process *process)
{
	int			fd[2];
	pid_t		father;

	if (process->forked == false)
		ft_fork(ast, shell, process, &ft_pipe);
	else
	{
		pipe(fd);
		father = fork();
		if (father != -1)
		{
			if (father == 0)
			{
				read_pipe(fd);
				executing(ast->right, shell, process);
			}
			else
			{
				write_pipe(fd);
				executing(ast->left, shell, process);
			}
		}
	}
}
