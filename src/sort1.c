/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:10:30 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/12 20:12:32 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				up_or_down(t_stack *b, int i)
{
	t_stack		*tmp;
	int			k;

	tmp = b;
	k = 0;
	while (tmp && tmp->index != i)
	{
		k++;
		tmp = tmp->next;
	}
	if (k < len_stk(b) - k + 1)
		return (1);
	return (0);
}

int				is_vseok(t_stack *b, int i)
{
	t_stack		*tmp;
	int			f;

	tmp = b;
	f = 0;
	while (tmp && tmp->index != i)
	{
		if (tmp->index == i - 1)
			f += 1;
		if (tmp->index == i - 2)
			f += 2;
		if (tmp->index == i - 3)
			f += 100;
		tmp = tmp->next;
	}
	if (f == 103)
		return (3);
	if (f == 3)
		return (2);
	if (f == 1)
		return (1);
	return (0);
}

int				find_i(t_stack **b, int i, int j)
{
	while ((*b)->index > i || (*b)->index < j)
	{
		rb(b);
	}
	return (1);
}

t_stack			*find_i_down(t_stack **b, int i, int j)
{
	t_stack		*last;

	last = last_list_ps(*b);
	while (last->index > i || last->index < j)
	{
		rrb(b);
		last = last_list_ps(*b);
	}
	return (last);
}

int				is_vseok_down(t_stack *b, int i)
{
	t_stack		*tmp;
	int			f;

	tmp = b;
	f = 0;
	while (tmp && tmp->index != i)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->index == i - 1)
			f += 1;
		if (tmp->index == i - 2)
			f += 2;
		if (tmp->index == i - 3)
			f += 100;
		tmp = tmp->next;
	}
	if (f == 103)
		return (3);
	if (f == 3)
		return (2);
	if (f == 1)
		return (1);
	return (0);
}
