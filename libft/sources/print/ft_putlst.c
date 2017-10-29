/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:05:57 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/06 07:50:13 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putlst(t_list *node)
{
	while (node)
	{
		ft_putendl(node->str);
		node = node->next;
	}
}
