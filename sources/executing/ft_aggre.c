/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aggre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:47:40 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:59:24 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str, char *err, unsigned char *ret)
{
	ft_putstr_fd("21sh: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
	*ret = 1;
	exit(EXIT_FAILURE);
}

static int		get_std(bool flag, char *operater, char *str,
				unsigned char *ret)
{
	size_t		index;
	int			direction;
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
		flag == false ? error(str, "Ambiguous redirect", ret) : 0;
		new = ft_strsub(operater, 0, index);
		direction = ft_atoi(new);
		ft_memdel((void **)&new);
		return (direction);
	}
	return (-1);
}

static int		open_fd(int *fd, char *str, unsigned char *ret)
{
	if (ft_strdigit(str))
	{
		*fd = ft_atoi(str);
		*fd > 3 ? error(str, "Bad file descriptor", ret) : 0;
		return (true);
	}
	else if (!ft_strcmp(str, "-"))
	{
		*fd = open("/dev/null", O_RDWR);
		*fd == -1 ? exit(EXIT_FAILURE) : 0;
		return (true);
	}
	else
		*fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	return (false);
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_aggre(t_ast *ast, t_line *line, t_process *process)
{
	int			fd;
	bool		flag;
	int			std;

	if (process->forked == false)
		ft_fork(ast, line, process, &ft_aggre);
	else
	{
		flag = open_fd(&fd, ast->right->command[0], &process->ret);
		std = get_std(flag, ast->operater, ast->right->command[0],
																&process->ret);
		if (std == -1)
		{
			dup2(fd, STDOUT_FILENO);
			dup2(fd, STDERR_FILENO);
			dup2(fd, STDIN_FILENO);
		}
		else
			dup2(fd, std);
		executing(ast->left, line, process);
		close(fd);
	}
}
