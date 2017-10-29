/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:46:54 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 14:11:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PUBLIC *********************************************************
*/

bool			chk_operaters(char c)
{
	size_t		index;
	const char	*str;

	index = 0;
	str = "&|<>;";
	if (c)
	{
		while (str[index])
		{
			if (c == str[index])
				return (true);
			index++;
		}
	}
	return (false);
}

bool			chk_slash(const char *str, size_t index)
{
	size_t		occurence;

	occurence = 0;
	while (str[index])
	{
		if (str[index] == '\\')
			occurence++;
		else
			break ;
		index--;
	}
	return (occurence % 2 == 0 ? true : false);
}

void			chk_quotes(char c, char quote, const int *flag, int *value)
{
	if (*flag == 0)
	{
		if (c == quote)
			*value = *value == 0 ? 1 : 0;
	}
}

void			iteration(t_list *node, char **env, unsigned char ret,
				void (*f)(char **str, char **env, unsigned char ret))
{
	size_t		index;

	index = 0;
	while (node)
	{
		if (index % 2 == 0)
			f(&node->str, env, ret);
		index++;
		node = node->next;
	}
}
