/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occurence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:42:53 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 15:43:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

size_t			ft_occurence(char *str, char c)
{
	size_t		index;
	size_t		occurence;

	index = 0;
	occurence = 0;
	if (str)
	{
		while (str[index])
		{
			if (str[index] == c)
				occurence++;
			index++;
		}
	}
	return (occurence);
}
