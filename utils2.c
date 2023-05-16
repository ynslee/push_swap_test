/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:05:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/16 15:05:29 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort top 2 or 3 of the stack_a*/
void	top_sort_a(t_ps *ps, int length)
{
	if (sorted_orderly(ps->a, ps->len_a) == 1 || length == 1)
		return ;
	else if (length == 2)
	{
		sa(ps);
		return ;
	}
	else if (length == 3 && ps->a[0] < ps->a[1] && ps->a[0] < ps->a[2])
	{	
		pb(ps);
		sa(ps);
	}
	else if (length == 3 && ps->a[2] < ps->a[1] && ps->a[2] < ps->a[0])
	{
		if (ps->a[0] > ps->a[1])
			sa(ps);
		ra(ps);
		sa(ps);
		pb(ps);
		rra(ps);
	}		
	else if (length == 3 && ps->a[1] < ps->a[0] && ps->a[1] < ps->a[2])
	{
		if (ps->a[0] < ps->a[2])
		{
			sa(ps);
			return ;
		}
		else
		{
			sa(ps);
			pb(ps);
			sa(ps);
		}
	}
	pa(ps);
}

void	top_sort_a2(t_ps *ps)
{
	if (ps->a[0] < ps->a[2])
	{
		sa(ps);
		return ;
	}
	else
	{
		sa(ps);
		pb(ps);
		sa(ps);
	}
}

void	free_all(t_ps *ps)
{
	if (ps->array)
		free(ps->array);
	if (ps->a)
		free(ps->a);
	if (ps->b)
		free(ps->b);
	if (ps->real_argv)
		free_char_array(ps);
	ps->array = NULL;
	ps->a = NULL;
	ps->b = NULL;
}

void	free_char_array(t_ps *ps)
{
	int	i;

	i = 0;

	ft_printf("in free_char_array func\n");
	while (i < ps->real_argc)
	{
		free(ps->real_argv[i]);
		ps->real_argv[i] = NULL;
		i++;
	}
	free(ps->real_argv);
}
