/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:54 by yoonslee          #+#    #+#             */
/*   Updated: 2023/05/16 14:53:52 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_ps(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*Checks if argv is numbers only*/
void	arg_is_number(int i, int j, int neg, t_ps *ps)
{
	long long int	res;

	while (i < ps->real_argc)
	{
		neg = 1;
		res = 0;
		j = 0;
		if (ps->real_argv[i][j] == '-')
			neg = -1;
		if (ps->real_argv[i][j] == '+' || ps->real_argv[i][j] == '-')
			j++;
		if (!ps->real_argv[i][j])
			ft_error();
		while (j < ft_strlen_ps(ps->real_argv[i]))
		{
			if (ft_isdigit(ps->real_argv[i][j]) == 0)
				ft_error();
			res = res * 10 + (ps->real_argv[i][j] - 48);
			j++;
		}
		if ((neg * res) > 2147483647 || (neg * res) < -2147483648)
			ft_error();
		ps->a[i] = neg * res;
		i++;
	}
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: error if a duplicate is found, 0 if there are none.
*/
static int	have_duplicates(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->real_argc)
	{
		j = i + 1;
		while (j < ps->real_argc)
		{
			if (j != i && ft_strcmp(ps->real_argv[i], ps->real_argv[j]) == 0)
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}

/*  Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.*/
int	check_real_argv(t_ps *ps)
{
	int	i;
	int	j;
	int	neg;

	i = 0;
	j = 0;
	neg = 1;
	if (have_duplicates(ps) != 0)
		return (0);
	arg_is_number(i, j, neg, ps);
	return (1);
}
