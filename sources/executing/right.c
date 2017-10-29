/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:08:02 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 13:02:09 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

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

void			right(t_ast *ast, t_line *line, t_process *process)
{
	size_t		std;
	size_t		length;
	int			type;
	int			fd;

	if (process->forked == false)
		ft_fork(ast, line, process, &right);
	else
	{
		std = get_std(ast->operater);
		length = ft_intlen(std);
		type = ft_strncmp(ast->operater + length, ">>", 2) == 0 ?
															O_APPEND : O_TRUNC;
		fd = open(*ast->right->command, O_RDWR | O_CREAT | type, 0644);
		if (fd > 0)
		{
			dup2(fd, std);
			executing(ast->left, line, process);
			close(fd);
		}
		else
			exit(EXIT_FAILURE);
	}
}
