/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:49:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 22:06:46 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
******* PUBLIC *****************************************************************
*/

void	ft_echo(char **command, char ***env __attribute__((unused)),
		unsigned char *ret)
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
