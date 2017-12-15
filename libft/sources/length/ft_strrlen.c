/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:20:29 by jefferso          #+#    #+#             */
/*   Updated: 2017/11/03 19:09:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

size_t			ft_strrlen(const char *str, char c, size_t index)
{
	size_t		length;

	length = 0;
	if (str)
	{
		while (str[index])
		{
			if (str[index] == c)
				break ;
			index++;
			length++;
		}
	}
	return (length);
}
