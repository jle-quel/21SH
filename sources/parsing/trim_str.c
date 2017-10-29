/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:28:29 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:28:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static bool		chk(char *str, size_t start)
{
	while (str[start])
	{
		if (str[start] != ' ' && str[start] != ';')
			return (false);
		start++;
	}
	return (true);
}

static size_t	get_length(char *str, size_t start)
{
	size_t		index;

	index = 0;
	while (str[start])
	{
		if (chk(str, start) == true)
			break ;
		index++;
		start++;
	}
	return (index);
}

static size_t	get_skip(char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
	{
		if (str[index] != ' ' && str[index] != ';')
			break ;
		index++;
	}
	return (index);
}

/*
*************** PUBLIC *********************************************************
*/

void			trim_str(char **str)
{
	size_t		index;
	size_t		length;
	char		*new;

	if (*str)
	{
		index = get_skip(*str);
		length = get_length(*str, index);
		new = ft_strsub(*str, index, length);
		ft_memdel((void **)str);
		*str = new;
	}
}
