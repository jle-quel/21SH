/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:20:13 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/30 17:06:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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
