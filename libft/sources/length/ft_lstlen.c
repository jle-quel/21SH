/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:21:45 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:22:24 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_lstlen(t_list *node)
{
	size_t	index;

	index = 0;
	while (node)
	{
		index++;
		node = node->next;
	}
	return (index);
}
