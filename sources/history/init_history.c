/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:06:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 20:09:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static int		convert_to_hist(char *buff)
{
	static t_read	*read_std;
	static int		cmd_len;
	int				i;

	if (((i = -1) && !buff) || cmd_len == 500)
		return (0);
	if (!read_std)
	{
		cmd_len = 0;
		read_std = init_struct_for_read();
		read_std->history = 1;
	}
	while (buff[++i])
		if (ft_isprint(buff[i]) && ++cmd_len)
			key_print_fct(read_std->cmd, buff[i]);
	if (check_cmd(&read_std) && ++cmd_len)
	{
		key_print_fct(read_std->cmd, 10);
		return (0);
	}
	else if (!(cmd_len = 0) && make_list_hist(read_std))
		read_std = NULL;
	return (1);
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			init_history(char **env)
{
	int			fd;
	char		*buff;
	int			command;
	char		*pathname;

	pathname = ft_strjoin(ft_getenv(env, "HOME"), "/.21sh_history");
	save_home(pathname);
	if ((fd = open(pathname, O_RDONLY)) != -1)
	{
		command = 0;
		buff = NULL;
		while (command < HISTSIZE && get_next_line(fd, &buff))
		{
			command += convert_to_hist(buff);
			ft_memdel((void **)&buff);
		}
		close(fd);
	}
	ft_memdel((void **)&pathname);
	return ((uint8_t)(fd != 1 ? 0 : 1));
}
