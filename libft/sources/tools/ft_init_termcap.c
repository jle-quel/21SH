/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_termcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:18:30 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 17:00:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_init_termcap(void)
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
}
