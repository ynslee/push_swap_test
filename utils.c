/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:36:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/16 13:38:08 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_ps *ps)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (i < ps->len_a)
	{
		if (ps->a[i] < ps->a[temp])
				temp = i;
		i++;
	}
	return (temp);
}

void	reverse_sort(t_ps *ps, int length)
{
	while (length-- > 0)
		pa(ps);
	return ;
}

void	check_rotate(t_ps *ps)
{
	int	i;
	int	temp;	

	if (ps->a[0] >= ps->median)
	{
		i = 1;
		while (i < ps->len_a)
		{
			if (ps->a[i] < ps->median && i <= (ps->len_a / 2))
			{
				temp = i;
				while (temp-- > 0)
					ra(ps);
				return ;
			}
			else if (ps->a[i] < ps->median && i > (ps->len_a / 2))
			{
				temp = i;
				while (temp-- > 0)
					rra(ps);
				return ;
			}
			i++;
		}
	}
}

/*if the chunk is small or less than 3, you continue into sorting.
if chunk is bigger, you cut it and send it back to a*/
void	top_sort_b(t_ps *ps)
{
	if (ps->count == 2)
	{
		if (ps->b[0] < ps->b[1])
			sb(ps);
	}
	if (ps->count == 3 && ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2])
	{
		pa(ps);
		sb(ps);
	}
	else if (ps->count == 3 && ps->b[2] > ps->b[1] && ps->b[2] > ps->b[0])
	{
		if (ps->b[0] < ps->b[1])
			sb(ps);
		rb(ps);
		sb(ps);
		pa(ps);
		rrb(ps);
	}
	else if (ps->count == 3 && ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
		top_sort_b2(ps);
	pa(ps);
	pa(ps);
}

void	top_sort_b2(t_ps *ps)
{
	sb(ps);
	pa(ps);
	if (ps->b[0] < ps->b[1])
		sb(ps);
}
