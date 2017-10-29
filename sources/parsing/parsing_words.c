/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:21:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/29 12:14:39 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str, t_list **node, unsigned char *ret)
{
	ft_putstr_fd("21sh: parse error near: ", 2);
	ft_putendl_fd(str, 2);
	ft_lstdel(node);
	*ret = 1;
}

static bool		chk(char *str)
{
	size_t		index;
	size_t		flag;

	index = 0;
	flag = 0;
	if (str)
	{
		while (str[index])
		{
			if (str[index] == ' ' || str[index] == '\t')
				flag++;
			index++;
		}
	}
	return (index == flag ? false : true);
}

static void		do_remove(char **str)
{
	size_t		index;
	size_t		i;
	size_t		occurence;
	char		*new;

	index = 0;
	i = 0;
	occurence = ft_occurence(*str, 10);
	new = (char *)ft_memalloc(sizeof(char) * (ft_strlen(*str) - occurence + 1));
	while ((*str)[i])
	{
		if ((*str)[i] == 10)
			i++;
		else
			new[index++] = (*str)[i++];
	}
	ft_memdel((void **)str);
	*str = new;
}

/*
*************** PUBLIC *********************************************************
*/

void			parsing_words(t_list **node, unsigned char *ret)
{
	size_t		index;
	char		err;
	t_list		*temp;

	index = 0;
	temp = *node;
	while (temp)
	{
		if (index % 2 == 0)
		{
			do_remove(&temp->str);
			err = chk(temp->str);
			if (err == false)
			{
				error(temp->prev->str, node, ret);
				return ;
			}
		}
		index++;
		temp = temp->next;
	}
}
