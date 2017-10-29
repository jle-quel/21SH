/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:05:36 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:21:12 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PRIVATE ********************************************************
*/

static bool		chk(char *str, size_t start)
{
	while (str[start])
	{
		if (str[start] != 32 && str[start] != 9)
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
		if (str[index] != 32 && str[index] != 9)
			break ;
		index++;
	}
	return (index);
}

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strtrim(char *str)
{
	size_t		index;
	size_t		length;
	char		*new;

	new = NULL;
	if (str)
	{
		index = get_skip(str);
		length = get_length(str, index);
		new = ft_strsub(str, index, length);
	}
	return (new);
}
