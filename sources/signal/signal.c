/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:00:37 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:28:59 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

void			handle(int sig)
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\2\0");
		signal_reception(1);
	}
	else if (sig == SIGWINCH)
	{
		ft_termcap("cl", 0);
		tgetent(NULL, handler(NULL));
		ioctl(STDIN_FILENO, TIOCSTI, "\0");
	}
	else
		signal(sig, SIG_DFL);
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_signal(void)
{
	int			index;

	index = 0;
	while (index < 32)
	{
		signal(index, &handle);
		index++;
	}
}
