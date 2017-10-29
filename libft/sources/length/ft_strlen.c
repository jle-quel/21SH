/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 06:37:12 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 06:40:45 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	if (str)
	{
		while (str[index])
			index++;
	}
	return (index);
}
