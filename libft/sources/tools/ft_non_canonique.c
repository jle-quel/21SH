/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_non_canonique.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:17:26 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 16:21:09 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_non_canonique(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl_fd("21sh: Informations couldn't be found", 2);
		exit(EXIT_FAILURE);
	}
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == 1)
	{
		ft_putstr_fd("21sh: Couldn't change value of struct termios", 2);
		exit(EXIT_FAILURE);
	}
}
