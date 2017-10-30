/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:32:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/30 10:02:47 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** TOOLS **********************************************************
*/

static size_t	get_length(char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == ' ')
			break ;
		else if (str[index] == '\"')
			skip_quote(str, &index, '\"');
		else if (str[index] == '\'')
			skip_quote(str, &index, '\'');
		index++;
	}
	return (index);
}

/*
*************** PRIVATE ********************************************************
*/

static char		*get_word(char *str, size_t *index)
{
	size_t		length;
	char		*new;

	do_skip(str, index);
	length = get_length(str + *index);
	new = ft_strsub(str, *index, length);
	remove_quote(&new);
	*index += length;
	return (new);
}

static size_t	get_word_numbers(char *str)
{
	size_t		index;
	size_t		numbers;

	index = 0;
	do_skip(str, &index);
	numbers = str[index] ? 1 : 0;
	while (str[index])
	{
		if (str[index] == '\"')
			skip_quote(str, &index, '\"');
		else if (str[index] == '\'')
			skip_quote(str, &index, '\'');
		if (str[index] == ' ')
		{
			do_skip(str, &index);
			numbers += str[index] ? 1 : 0;
		}
		else
			index++;
	}
	return (numbers);
}

/*
*************** PUBLIC *********************************************************
*/

char			**split(char *str)
{
	size_t		index;
	size_t		length;
	size_t		word_numbers;
	char		**new;

	index = 0;
	length = 0;
	word_numbers = get_word_numbers(str);
	new = NULL;
	if (word_numbers)
	{
		new = (char **)ft_memalloc(sizeof(char *) * (word_numbers + 1));
		while (index < word_numbers)
			new[index++] = get_word(str, &length);
		new[index] = NULL;
	}
	else
	{
		new = (char **)ft_memalloc(sizeof(char *) * 2);
		new[0] = ft_strdup("");
		new[1] = NULL;
	}
	return (new);
}
