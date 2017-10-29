/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:20:13 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:20:14 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
******************* PUBLIC *****************************************************
*/

void				prompt_exec(char *command[], char **env, int fd)
{
	int			fd_err;
	int			err;
	pid_t		process;
	int			status;

	fd_err = open("/dev/null", O_RDWR);
	if (fd > 0 && fd_err > 0)
	{
		process = fork();
		if (process != -1)
		{
			if (process == 0)
			{
				dup2(fd, STDOUT_FILENO);
				dup2(fd_err, STDERR_FILENO);
				err = execve(command[0], command, env);
				err == -1 ? exit(EXIT_FAILURE) : 0;
			}
			else
				wait(&status);
		}
	}
	close(fd_err);
}

size_t				get_length_redirection(char *str, unsigned int index,
					char c)
{
	while (str[index])
	{
		if (str[index] != c)
			break ;
		index++;
	}
	return (index);
}

bool				chk_redirection(char c)
{
	short				index;
	static const char	chk[4] = {'<', ';', '|', '\0'};

	index = 0;
	while (chk[index])
	{
		if (c == chk[index])
			return (true);
		index++;
	}
	return (false);
}
