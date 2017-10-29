/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:58:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 18:52:20 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

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
	if (sig == SIGWINCH)
	{
		ft_termcap("cl", 0);
		tgetent(NULL, handler(NULL));
		ioctl(STDIN_FILENO, TIOCSTI, "\0");
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_signal(void)
{
	int			index;

	index = 0;
	while (index < 31)
	{
		signal(index, &handle);
		index++;
	}
}
