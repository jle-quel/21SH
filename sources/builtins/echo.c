/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:49:57 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 19:03:38 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

void			ft_echo(char **command, char ***env __attribute__((unused)),
				uint8_t *ret)
{
	size_t		index;

	index = 1;
	while (command[index])
	{
		ft_putstr(command[index]);
		command[index + 1] ? ft_putchar(32) : 0;
		index++;
	}
	ft_putchar(10);
	*ret = 0;
}
