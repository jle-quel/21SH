/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:47:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/19 10:47:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_ptrnext(t_list **node, size_t stop)
{
	size_t	index;

	index = 0;
	if (*node)
	{
		while ((*node)->next)
		{
			if (index == stop)
				break ;
			*node = (*node)->next;
			index++;
		}
	}
}
