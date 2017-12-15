/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:13:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/30 17:08:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

/*
*************** PRIVATE ********************************************************
*/

static char		*populate_prompt(const char *prompt, const char *branch,
				unsigned char ret)
{
	char		*new;

	new = (char*)ft_memalloc(sizeof(char) *
								(ft_strlen(prompt) + ft_strlen(branch) + 30));
	ft_strcpy(new, prompt);
	if (branch)
	{
		ft_strcat(new, " [");
		ft_strcat(new, branch);
		ft_strcat(new, "]");
	}
	if (ret == 0)
		ft_strcat(new, "\x1b[32m ❯\x1b[0m ");
	else
		ft_strcat(new, "\x1b[31m ❯\x1b[0m ");
	return (new);
}

/*
*************** PUBLIC *********************************************************
*/

char			*create_prompt(char **env __attribute__((unused)),
				unsigned char *ret)
{
	static char	*new;
	char		*prompt;
	char		*branch;

	ft_memdel((void **)&new);
	prompt = get_prompt(env);
	branch = get_branch(env);
	get_len_prompt(ft_strlen(prompt) + ft_strlen(branch) + (branch ? 6 : 3));
	new = populate_prompt(prompt ? prompt : "21sh", branch, *ret);
	ft_memdel((void **)&prompt);
	ft_memdel((void **)&branch);
	return (new);
}
