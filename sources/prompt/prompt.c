/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:11:33 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:00:26 by jle-quel         ###   ########.fr       */
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
	char		*prompt;

	fd = open("/tmp/.prompt", O_RDWR);
	if (fd > 0)
	{
		gnl(fd, &line);
		prompt = ft_strdup(ft_strlchr(line, '/'));
		ft_memdel((void **)&line);
		return (prompt);
	}
	return (NULL);
}

/*
*************** PUBLIC *********************************************************
*/

char			*get_prompt(char **env)
{
	int				fd;
	static char		*command[2] = {"/bin/pwd", NULL};
	char			*prompt;

	fd = open("/tmp/.prompt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd > 0)
	{
		prompt_exec(command, env, fd);
		close(fd);
		prompt = get_result();
		remove("/tmp/.prompt");
		return (prompt);
	}
	return (NULL);
}
