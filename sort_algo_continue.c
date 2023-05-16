/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_continue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:23:43 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/16 13:36:17 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort the small chunk in a and push back small chunk from b to a*/
void	sort_continue(t_ps *ps)
{
	int	temp;
	int	a_before;

	a_before = ps->len_a;
	ps->count = 0;
	while (ps->array[0] != 0)
	{
		ps->count = ps->array[0];
		temp = ps->count;
		if (sorted_reverse(ps->b, temp) == 1)
		{
			reverse_sort(ps, temp);
			remove_from_chunks(ps);
		}
		else if (ps->count <= 3)
		{
			top_sort_b(ps);
			remove_from_chunks(ps);
		}
		else if (ps->count > 3)
		{
			remove_from_chunks(ps);
			divide_b_to_a(ps, ps->count, ps->len_a, temp);
		}
	}
}

/*move the chunks back to stack_a*/
void	divide_b_to_a(t_ps *ps, int length, int a_before, int count)
{
	int	i;

	ps->count = 0;
	find_median_b(ps, length);
	while (ps->len_a - a_before < length / 2)
	{
		if (ps->b[0] > ps->median || (ps->b[0] > ps->median && length % 2 == 0))
			pa(ps);
		else
		{
			rb(ps);
			ps->count++;
		}
	}
	count = ps->count;
	i = ps->len_a - a_before;
	add_to_chunks(ps, length - i);
	while (count-- > 0 && length != ps->len_b)
		rrb(ps);
	divide_b_to_a2(ps, i, a_before);
}

void	divide_b_to_a2(t_ps *ps, int i, int a_before)
{
	if (i <= 3)
	{
		top_sort_a(ps, i);
		return ;
	}
	if (ps->len_a - a_before > 3)
		divide_a_to_b(ps, ps->len_a - a_before);
}

/*move the chunks back to stack_b after moving it to stack_a*/
void	divide_a_to_b(t_ps *ps, int left)
{
	int	length;
	int	b_before;
	int	i;

	i = 0;
	ps->count = 0;
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		return ;
	find_median_a(ps, left);
	length = left;
	b_before = ps->len_b;
	while (ps->count < length / 2)
	{
		if (ps->a[0] < ps->median || (ps->a[0] == ps->median && left % 2 == 0))
		{
			pb(ps);
			ps->count++;
		}
		else if (ps->a[0] >= ps->median)
		{
			ra(ps);
			i++;
		}
	}
	divide_a_to_b2(ps, i, left - ps->count);
}

void	divide_a_to_b2(t_ps *ps, int i, int leftover)
{
	while (i-- > 0)
		rra(ps);
	if (leftover <= 3)
		top_sort_a(ps, leftover);
	add_to_chunks(ps, ps->count);
	i = ps->count;
	if (leftover <= 3 && ps->count <= 3)
	{
		if (sorted_reverse(ps->b, i) == 1)
			reverse_sort(ps, i);
		else
			top_sort_b(ps);
		remove_from_chunks(ps);
	}
	if (leftover > 3)
		divide_a_to_b(ps, leftover);
}
