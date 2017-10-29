/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:21:27 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:23:01 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

static int		ft_countwords(const char *s, char c)
{
	int			index[2];

	index[0] = 0;
	index[1] = 0;
	while (*s != '\0')
	{
		if (index[0] == 1 && *s == c)
			index[0] = 0;
		if (index[0] == 0 && *s != c)
		{
			index[0] = 1;
			index[1]++;
		}
		s++;
	}
	return (index[1]);
}

static int		count_letters(const char *s, char c)
{
	int			count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

/*
*************** PUBLIC *********************************************************
*/

char			**ft_strsplit(const char *s, char c)
{
	size_t		index;
	size_t		length;
	char		**array;

	array = NULL;
	if (s && c)
	{
		index = 0;
		length = ft_countwords(s, c);
		array = (char**)ft_memalloc(sizeof(array) * (length + 1));
		while (length--)
		{
			while (*s && *s == c)
				s++;
			array[index] = ft_strsub(s, 0, count_letters(s, c));
			s = s + count_letters(s, c);
			index++;
		}
		array[index] = NULL;
	}
	return (array);
}
