/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:58:09 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/28 23:11:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		index;
	size_t		length;

	if (s1 && s2)
	{
		index = 0;
		length = 0;
		while (s1[index] != '\0')
			index++;
		while (length < n && s2[length] != '\0')
		{
			s1[index] = s2[length];
			index++;
			length++;
		}
		s1[index] = '\0';
	}
	return (s1);
}
