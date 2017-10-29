/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:06:56 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:16:52 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdel(t_list **node)
{
	t_list	*memory;

	while (*node)
	{
		memory = *node;
		*node = (*node)->next;
		ft_memdel((void **)&memory->str);
		ft_arraydel(&memory->argv);
		ft_memdel((void **)&memory);
	}
}
