/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:20:29 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 16:20:54 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strrlen(const char *str, char c, size_t index)
{
	size_t	length;

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
