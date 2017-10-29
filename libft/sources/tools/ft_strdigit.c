/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 15:08:14 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/14 15:10:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

bool			ft_strdigit(char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
	{
		if (ft_isdigit(str[index]) == 0)
			return (false);
		index++;
	}
	return (true);
}
