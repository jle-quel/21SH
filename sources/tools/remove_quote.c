/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:29:04 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/30 10:41:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		populate(char *new, char *str)
{
	size_t		i;
	size_t		index;
	int			s_quote;
	int			d_quote;

	i = 0;
	index = 0;
	s_quote = 0;
	d_quote = 0;
	while (str[index])
	{
		chk_quotes(str[index], '\"', &s_quote, &d_quote);
		chk_quotes(str[index], '\'', &d_quote, &s_quote);
		if (str[index] == '\"' && s_quote == 0)
			;
		else if (str[index] == '\'' && d_quote == 0)
			;
		else
		{
			new[i] = str[index];
			i++;
		}
		index++;
	}
}

static size_t	get_occurence(char *str, char quote, char nemesis)
{
	size_t		index;
	size_t		occurence;

	index = 0;
	occurence = 0;
	while (str[index])
	{
		if (str[index] == nemesis)
			skip_quote(str, &index, nemesis);
		else if (str[index] == quote)
			occurence++;
		index++;
	}
	return (occurence);
}

/*
*************** PUBLIC *********************************************************
*/

void			remove_quote(char **str)
{
	size_t		s_occurence;
	size_t		d_occurence;
	char		*new;

	s_occurence = get_occurence(*str, '\'', '\"');
	d_occurence = get_occurence(*str, '\"', '\'');
	if (s_occurence > 0 || d_occurence > 0)
	{
		new = (char *)ft_memalloc(sizeof(char) *
							(ft_strlen(*str) - s_occurence - d_occurence + 1));
		populate(new, *str);
		ft_memdel((void **)str);
		*str = new;
	}
}
