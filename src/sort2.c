/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:14:31 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/12 20:14:32 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				for_check_a(t_stack **a)
{
	t_stack		*alast;

	alast = NULL;
	while (!cheak_sort(*a))
	{
		alast = last_list_ps(*a);
		if ((*a)->next->index < (*a)->index)
		{
			sa(a);
		}
		else if (alast->index < (*a)->index || alast->index < (*a)->next->index)
		{
			rra(a);
		}
	}
	return (1);
}

int				sort5(t_stack **a, t_stack **b, int i)
{
	while (len_stk(*a) > 2 || !cheak_sort(*a))
	{
		if ((*a)->index > i - 3)
			ra(a);
		else
			pb(a, b);
	}
	while (!cheak_sort(*a) || (*b))
	{
		while ((*b)->index != (*a)->index - 1)
		{
			if ((*b)->index < (*a)->index - 3)
			{
				pa(b, a);
				if ((*a)->index == i - 3)
					ra(a);
			}
			else
				rb(b);
		}
		pa(b, a);
		for_check_a(a);
	}
	return (1);
}

int				sort2(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
	return (1);
}

int				sort3(t_stack **a)
{
	while (!cheak_sort(*a))
	{
		if ((*a)->index == 2)
			ra(a);
		else if ((*a)->next->index < (*a)->index)
			sa(a);
		else if ((*a)->next->next->index < (*a)->next->index)
			rra(a);
	}
	return (1);
}

void			go_lastchunk(t_stack **a, t_stack **b, int max)
{
	int			i;

	i = max - 1;
	while (len_stk(*a) != 1)
	{
		if ((*a)->index == i)
			ra(a);
		else
			pb(a, b);
	}
}
