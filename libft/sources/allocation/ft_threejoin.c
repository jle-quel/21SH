/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:24:17 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:25:09 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_threejoin(char *s1, char *separator, char *s2)
{
	char		*str;

	str = NULL;
	if (s1 && separator && s2)
	{
		str = (char*)ft_memalloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(separator) + ft_strlen(s2) + 1));
		ft_strcpy(str, s1);
		ft_strcat(str, separator);
		ft_strcat(str, s2);
	}
	return (str);
}
