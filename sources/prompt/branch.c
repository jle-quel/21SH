/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:12:13 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:11:44 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static char		*get_result(void)
{
	int			fd;
	char		*line;
	char		*branch;

	fd = open("/tmp/.branch", O_RDWR);
	branch = NULL;
	if (fd > 0)
	{
		gnl(fd, &line);
		if (line)
		{
			branch = ft_strchr(line, '*');
			branch = branch ? ft_strdup(branch + 2) : 0;
			ft_memdel((void **)&line);
		}
	}
	return (branch);
}

/*
*************** PUBLIC *********************************************************
*/

char			*get_branch(char **env)
{
	int				fd;
	static char		*command[3] = {"/usr/bin/git", "branch", NULL};
	char			*branch;

	fd = open("/tmp/.branch", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd > 0)
	{
		prompt_exec(command, env, fd);
		close(fd);
		branch = get_result();
		remove("/tmp/.branch");
		return (branch);
	}
	return (NULL);
}
