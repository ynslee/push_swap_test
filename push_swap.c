/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:11:53 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/16 17:29:06 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		i;

	i = 0;
	ps = malloc(sizeof(t_ps));
	if (!ps)
		msg_error("malloc fail", 1);
	if (argc == 1)
		return (0);
	get_real_args(argc, argv, ps);
	// while (ps->real_argv[i] != '\0')
	// {
	// 	ft_printf("real argv is %s\n", ps->real_argv[i]);
	// 	i++;
	// }
	if (init_stack(ps) != 1)
		exit(1);
	check_real_argv(ps);
	sort_init(ps);
	free_all(ps);
	free(ps);
	return (0);
}
