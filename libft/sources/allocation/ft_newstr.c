/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferson <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:30:49 by jefferson         #+#    #+#             */
/*   Updated: 2017/10/28 23:25:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** TOOLS **********************************************************
*/

static size_t	get_occurence(char *str, char c)
{
	size_t		index;
	size_t		occurence;

	index = 0;
	occurence = 0;
	while (str[index])
	{
		if (str[index] == c)
			occurence++;
		index++;
	}
	return (occurence);
}

/*
*************** PUBLIC *********************************************************
*/

void			ft_newstr(char **str, char c)
{
	size_t		i;
	size_t		index;
	size_t		occurence;
	char		*new;

	i = 0;
	index = 0;
	occurence = get_occurence(*str, c);
	new = (char *)ft_memalloc(sizeof(char) * (ft_strlen(*str) - occurence + 1));
	while ((*str)[index])
	{
		if ((*str)[index] != c)
		{
			new[i] = (*str)[index];
			i++;
		}
		index++;
	}
	ft_memdel((void **)str);
	*str = new;
}
