/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:47:35 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/06 20:35:11 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static size_t	populate_until(char *new, char *str)
{
	size_t		index;
	size_t		length;

	length = 0;
	if (new && str)
	{
		index = 0;
		while (str[length])
		{
			if (str[length] == '\\')
				break ;
			new[index++] = str[length++];
		}
		length++;
	}
	return (length);
}

/*
*************** PRIVATE ********************************************************
*/

static void		expansion(char **str)
{
	size_t		length;
	char		*new;

	if (str && *str)
	{
		new = ft_memalloc(ft_strlen(*str));
		length = populate_until(new, *str);
		ft_strcat(new, (*str) ? (*str) + length : NULL);
		ft_memdel((void **)str);
		*str = new;
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			backslash(t_parsing *node)
{
	size_t		index;
	uint8_t		status;

	status = DEFAULT;
	while (node)
	{
		if (node->input)
		{
			index = 0;
			while (node->input[index])
			{
				chk_quote(node->input[index], &status);
				if (status & (DEFAULT | DQUOTE) && node->input[index] == '\\')
				{
					expansion(&node->input);
					if (node->input[index] && node->input[index] == '\\')
						index++;
				}
				else
					index++;
			}
		}
		node = node->next;
	}
}
