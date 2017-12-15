/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:40:38 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/02 13:04:55 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

static const t_cmp		g_tab_are_key[] =
{
		(t_cmp){KEY_EOF, key_eof},
		(t_cmp){DELETE_KEY, key_del},
		(t_cmp){CLEAR_KEY, key_clear_},
		(t_cmp){HOME_KEY, key_home_},
		(t_cmp){DEL_KEY, key_delete_here},
		(t_cmp){END_KEY, key_end_},
		(t_cmp){ARROW_LEFT, key_arrow_left},
		(t_cmp){ARROW_RIGHT, key_arrow_right},
		(t_cmp){ARROW_UP, key_arrow_up},
		(t_cmp){ARROW_DOWN, key_arrow_down},
		(t_cmp){SHIFT_UP_KEY, key_shift_up},
		(t_cmp){SHIFT_DOWN_KEY, key_shift_down},
		(t_cmp){SHIFT_RIGHT_KEY, key_shift_right},
		(t_cmp){SHIFT_LEFT_KEY, key_shift_left},
		(t_cmp){0, NULL}
};

/*
*************** PRIVATE ********************************************************
*/

static int		chk_and_print(t_read **read_std)
{
	print_struct(*read_std);
	(*read_std)->print = 0;
	return (1);
}

static void		initialize_fct(t_read **read_std __attribute__((unused)),
				unsigned char flags, t_shell *shell, t_process *process)
{
	ft_non_canonique();
	signal_reception(0);
	(*read_std)->cur = prompt(flags | PRINT, shell->env, &(process->ret));
}

static void		inline_print_(t_read **read_std, unsigned long *buff)
{
	if (!*buff)
		(*read_std)->print = 2;
	key_print_(read_std, buff);
	chk_and_print(read_std);
}

static void		inline_other(t_read **read_std, unsigned long *buff,
				int (*fct)(t_read **, unsigned long))
{
	fct(read_std, *buff);
	chk_and_print(read_std);
	*buff = 0;
}

/*
*************** PUBLIC *********************************************************
*/

t_cmd			*read_stdin(unsigned char flags, t_shell *shell,
				t_process *process)
{
	t_read					*read_std;
	int						index;
	static unsigned long	buf;

	read_std = init_struct_for_read();
	initialize_fct(&read_std, flags, shell, process);
	inline_print_(&read_std, &buf);
	while (!read_std->finish && read(STDIN_FILENO, &buf, sizeof(unsigned long)))
	{
		if (ft_isprint(buf % (UCHAR_MAX + 1)) ||
				ft_iscrlf(buf % (UCHAR_MAX + 1)) || !buf)
			inline_print_(&read_std, &buf);
		index = -1;
		while (g_tab_are_key[++index].key)
			if (g_tab_are_key[index].key == buf)
				inline_other(&read_std, &buf, g_tab_are_key[index].f);
		if ((read_std)->finish || signal_reception(-1))
			break ;
		buf = 0;
	}
	return (finish_read_std(&read_std));
}
