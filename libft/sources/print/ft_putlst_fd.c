/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:06:40 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:50:17 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putlst_fd(t_list *node, int fd)
{
	if (fd >= 0)
	{
		while (node)
		{
			ft_putendl_fd(node->str, fd);
			node = node->next;
		}
	}
}
