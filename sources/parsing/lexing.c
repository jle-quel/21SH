/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:58:36 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:23:58 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static size_t	get_length(char *str, size_t index, bool rounds)
{
	size_t		length;
	int			s_quote;
	int			d_quote;

	length = 0;
	s_quote = 0;
	d_quote = 0;
	while (str[index])
	{
		if (chk_slash(str, index - 1) == true)
		{
			chk_quotes(str[index], '\"', &s_quote, &d_quote);
			chk_quotes(str[index], '\'', &d_quote, &s_quote);
			if (s_quote == 0 && d_quote == 0 &&
											chk_operaters(str[index]) == rounds)
				return (length);
		}
		index++;
		length++;
	}
	return (length);
}

/*
*************** PUBLIC *********************************************************
*/

void			lexing(t_list **node, char *str)
{
	size_t	index;
	size_t	length;
	bool	rounds;
	char	*word;

	if (str)
	{
		index = 0;
		rounds = true;
		while (str[index])
		{
			length = get_length(str, index, rounds);
			rounds = rounds == true ? false : true;
			word = ft_strsub(str, index, length);
			ft_lstnew(node, word, NULL, 0);
			ft_memdel((void **)&word);
			index += length;
		}
	}
}
