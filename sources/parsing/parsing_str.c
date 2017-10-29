/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:29:26 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:19:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		print_err(char *str, size_t index)
{
	while (str[index])
	{
		if (chk_operaters(str[index]) == false)
			break ;
		ft_putchar_fd(str[index++], 2);
	}
	ft_putchar_fd(10, 2);
}

static void		reverse(char *str, size_t index)
{
	while (str[index])
	{
		index--;
		if (chk_operaters(str[index]) == false)
			break ;
	}
	print_err(str, index + 1);
}

static void		error(char **str, size_t index, unsigned char *ret)
{
	ft_putstr_fd("21sh: parse error near: ", 2);
	index == 0 ? print_err(*str, index) : reverse(*str, index);
	ft_memdel((void **)str);
	*ret = 1;
}

/*
*************** PUBLIC *********************************************************
*/

void			parsing_str(char **str, unsigned char *ret)
{
	size_t		length;

	if (*str)
	{
		length = ft_strlen(*str) - 1;
		if (chk_operaters((*str)[0]) == true)
			error(str, 0, ret);
		else if (chk_operaters((*str)[length]) == true)
			error(str, length, ret);
	}
}
