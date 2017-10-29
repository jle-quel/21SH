/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:38:16 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 22:21:15 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

int				ft_termcap(char *str, int fd)
{
	char		*termcap;

	if (!(termcap = tgetstr(str, NULL)))
	{
		ft_putendl_fd("Termcap for cursor couldn't be found", 2);
		return (-1);
	}
	ft_putstr_fd(termcap, fd);
	return (0);
}
