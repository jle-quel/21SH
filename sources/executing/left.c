/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:15:43 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 18:47:42 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		get_read(t_ast *ast, uint8_t *ret)
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
	{
		error(ast->command[0], ret, FILE_404);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_left(t_ast *ast, t_shell *shell, t_process *process)
{
	int			status;
	int			fd[2];
	pid_t		father;

	if (process->forked == false)
		ft_fork(ast, shell, process, &ft_left);
	else
	{
		pipe(fd);
		father = fork();
		if (father == 0)
		{
			write_pipe(fd);
			get_read(ast->right, &(process->ret));
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
