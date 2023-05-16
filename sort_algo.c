/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:08 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/16 13:30:10 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check if stack A is sorted already. If not, continue to sort*/
void	sort_init(t_ps *ps)
{
	if (ps->len_a == 1)
		exit(0);
	if (sorted_orderly(ps->a, ps->len_a) == 1)
		exit(0);
	if (ps->len_a <= 5)
	{
		small_sort(ps);
		exit(0);
	}
	else if (ps->len_a > 5)
		sort_to_b(ps);
	small_sort(ps);
	sort_continue(ps);
	return ;
}

/*find the median and push it to stack b*/
void	sort_to_b(t_ps *ps)
{
	int	len;
	int	b_before;

	if (ps->len_a <= 5)
		return ;
	b_before = ps->len_b;
	ps->count = 0;
	find_median_a(ps, ps->len_a);
	len = ps->len_a;
	while (ps->len_b - b_before < len / 2)
	{
		if (ps->a[0] < ps->median || (ps->a[0] == ps->median && len % 2 == 0))
			pb(ps);
		else
			ra(ps);
	}
	add_to_chunks(ps, ps->len_b - b_before);
	if (ps->len_a > 5)
		sort_to_b(ps);
}
