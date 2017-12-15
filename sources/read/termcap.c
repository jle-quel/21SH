/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:00:02 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 22:00:04 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			*handler(char *err)
{
	static char	*save;

	if (err)
		save = err;
	return (save);
}

void			init_termcap(void)
{
	int			result;
	char		*terminal_type;

	if (!(terminal_type = getenv("TERM")))
	{
		ft_putendl_fd("21sh: Variable $TERM is not defined", 2);
		exit(EXIT_FAILURE);
	}
	if ((result = tgetent(NULL, terminal_type)) == 0)
	{
		ft_putendl_fd("21sh: No such entry", 2);
		exit(EXIT_FAILURE);
	}
	if (result == -1)
	{
		ft_putendl_fd("21sh: Terminfo database couldn't be found", 2);
		exit(EXIT_FAILURE);
	}
	handler(terminal_type);
}
