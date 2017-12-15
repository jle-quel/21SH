/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:51:22 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 19:52:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static int		get_std(char *operater)
{
	size_t		index;
	size_t		direction;
	char		*new;

	index = 0;
	while (operater[index])
	{
		if (ft_isdigit(operater[index]) != 1)
			break ;
		index++;
	}
	if (index > 0)
	{
		new = ft_strsub(operater, 0, index);
		direction = ft_atoi(new);
		ft_memdel((void **)&new);
		return (direction);
	}
	return (1);
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_right(t_ast *ast, t_shell *shell, t_process *process)
{
	size_t		std;
	size_t		length;
	int			type;
	int			fd;

	if (process->forked == false)
		ft_fork(ast, shell, process, &ft_right);
	else
	{
		std = get_std(ast->command[0]);
		length = ft_intlen(std);
		type = ft_strncmp(ast->command[0] + length, ">>", 2) == 0 ?
															O_APPEND : O_TRUNC;
		fd = open(*ast->right->command, O_RDWR | O_CREAT | type, 0644);
		if (fd > 0)
		{
			dup2(fd, std);
			executing(ast->left, shell, process);
			close(fd);
		}
		else
			exit(EXIT_FAILURE);
	}
}
