/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:29:04 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 16:10:14 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		populate(char *str, char *new)
{
	size_t		i;
	size_t		index;
	bool		flag;

	i = 0;
	index = 0;
	flag = false;
	while (str[index])
	{
		if (str[index] == '\"')
			flag = flag == false ? true : false;
		if (str[index] != '\"')
		{
			if (str[index] == '\'' && flag == false)
				;
			else
				new[i++] = str[index];
		}
		index++;
	}
}

static size_t	get_occurence(char *str)
{
	size_t		index;
	size_t		occurence;
	bool		flag;

	index = 0;
	occurence = 0;
	flag = false;
	while (str[index])
	{
		if (str[index] == '\"')
			flag = flag == false ? true : false;
		if (str[index] == '\'' && flag == false)
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
	size_t		d_occurence;
	size_t		s_occurence;
	char		*new;

	d_occurence = ft_occurence(*str, '\"');
	s_occurence = get_occurence(*str);
	if (d_occurence > 0 || s_occurence > 0)
	{
		new = (char *)ft_memalloc(sizeof(char) *
		((ft_strlen(*str)) - d_occurence - s_occurence + 1));
		populate(*str, new);
		ft_memdel((void **)str);
		*str = new;
	}
}
