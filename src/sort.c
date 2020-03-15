/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:07:53 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/05 18:07:54 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		go_outb_up_end(t_stack **a, t_stack **b, t_sort p)
{
	pa(b, a);
	if (p.k == 1)
		sa(a);
	if (p.f == 1)
		rra(a);
	if (p.w == 1)
	{
		rra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}

void		go_outb_up(t_stack **a, t_stack **b, int i)
{
	t_sort	p;

	p = (t_sort){0, 0, 0, is_vseok(*b, i)};
	while (find_i(b, i, i - p.ok))
	{
		if ((*b)->index == i - 3)
		{
			p.w = 1;
			pa(b, a);
			ra(a);
		}
		else if ((*b)->index == i - 2)
		{
			p.f = 1;
			pa(b, a);
			ra(a);
		}
		else if ((*b)->index == i - 1)
		{
			p.k = 1;
			pa(b, a);
		}
		else if ((*b)->index == i)
			return (go_outb_up_end(a, b, p));
	}
}

void		go_outb_down_end(t_stack **a, t_stack **b, t_sort p)
{
	rrb(b);
	pa(b, a);
	if (p.k == 1)
		sa(a);
	if (p.f == 1)
		rra(a);
	if (p.w == 1)
	{
		rra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}

void		go_outb_down3(t_stack **a, t_stack **b, t_sort *p)
{
	p->w = 1;
	rrb(b);
	pa(b, a);
	ra(a);
}

void		go_outb_down(t_stack **a, t_stack **b, int i)
{
	t_stack *last;
	t_sort	p;

	p = (t_sort){0, 0, 0, is_vseok_down(*b, i)};
	while (1)
	{
		last = find_i_down(b, i, i - p.ok);
		if (last->index == i - 3)
			go_outb_down3(a, b, &p);
		else if (last->index == i - 2)
		{
			p.f = 1;
			rrb(b);
			pa(b, a);
			ra(a);
		}
		else if (last->index == i - 1)
		{
			p.k = 1;
			rrb(b);
			pa(b, a);
		}
		else if (last->index == i)
			return (go_outb_down_end(a, b, p));
	}
}
