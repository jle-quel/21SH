/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 08:04:32 by jefferso          #+#    #+#             */
/*   Updated: 2017/10/28 23:19:39 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PRIVATE ********************************************************
*/

static void		add_size(char **buff, int *max_len)
{
	char *tmp;

	tmp = (char *)ft_memalloc(sizeof(char) * ((*max_len) + 101));
	ft_strncpy(tmp, *buff, *max_len);
	*max_len += 100;
	ft_memdel((void **)buff);
	(*buff) = tmp;
}

/*
*************** PUBLIC *********************************************************
*/

int				gnl(int fd, char **line)
{
	int		max_len;
	int		i;
	int		ret;

	if (fd == -1 || !line)
		return (0);
	i = -1;
	max_len = 100;
	(*line) = (char *)ft_memalloc(sizeof(char) * (max_len + 1));
	while ((ret = read(fd, &((*line)[++i]), sizeof(char))) > 0)
	{
		if ((*line)[i] == 10)
			break ;
		if (i == max_len)
			add_size(line, &max_len);
	}
	if (i)
	{
		(*line)[i] = '\0';
		return (1);
	}
	else
		ft_memdel((void **)line);
	return (ret);
}
