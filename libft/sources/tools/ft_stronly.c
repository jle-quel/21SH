/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:13:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/19 14:24:23 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

bool			ft_stronly(char *str, char c)
{
	size_t		index;

	if (str && c)
	{
		index = 0;
		while (str[index])
		{
			if (str[index] != c)
				return (false);
			index++;
		}
		return (true);
	}
	return (false);
}
