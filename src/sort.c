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

int 		up_or_down(t_stack *b, int i)
{
	t_stack *tmp;
	int		k;

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

int 		is_vseok(t_stack *b, int i)
{
	t_stack		*tmp;
	int 		f;

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

void		find_i(t_stack **b, int i, int j)
{
	while ((*b)->index > i || (*b)->index < j)
	{
		rb(b);
	}
}

void		go_outb_up(t_stack **a, t_stack **b, int i)
{
	int 	f;
	int 	k;
	int		w;
	int 	ok;

	f = 0;
	k = 0;
	w = 0;
	ok = is_vseok(*b, i);
	while (1)
	{
		find_i(b, i, i - ok);
		if ((*b)->index == i - 3)
		{
			w = 1;
			pa(b, a);
			ra(a);
		}
		else if ((*b)->index == i - 2)
		{
			f = 1;
			pa(b, a);
			ra(a);
		}
		else if ((*b)->index == i - 1)
		{
			k = 1;
			pa(b, a);
		}
		else if ((*b)->index == i)
		{
			pa(b, a);
			if (k == 1)
				sa(a);
			if (f == 1)
				rra(a);
			if (w == 1)
			{
				rra(a);
				if ((*a)->index > (*a)->next->index)
					sa(a);
			}
			break ;
		}
	}
}

t_stack 	*find_i_down(t_stack  **b, int i, int j)
{
	t_stack *last;

	last = last_list_ps(*b);
	while (last->index > i || last->index < j)
	{
		rrb(b);
		last = last_list_ps(*b);
	}
	return (last);
}

int 		is_vseok_down(t_stack *b, int i)
{
	t_stack		*tmp;
	int 		f;

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

void		go_outb_down(t_stack **a, t_stack **b, int i)
{
	t_stack *last;
	int 	f;
	int 	k;
	int		w;
	int 	ok;

	f = 0;
	k = 0;
	w = 0;
	ok = is_vseok_down(*b, i);
	while (1)
	{
		last = find_i_down(b, i, i - ok);
		if (last->index == i - 3)
		{
			w = 1;
			rrb(b);
			pa(b, a);
			ra(a);
		}
		else if (last->index == i - 2)
		{
			f = 1;
			rrb(b);
			pa(b, a);
			ra(a);
		}
		else if (last->index == i - 1)
		{
			k = 1;
			rrb(b);
			pa(b, a);
		}
		else if (last->index == i)
		{
			rrb(b);
			pa(b, a);
			if (k == 1)
				sa(a);
			if (f == 1)
				rra(a);
			if (w == 1)
			{
				rra(a);
				if ((*a)->index > (*a)->next->index)
					sa(a);
			}
			break ;
		}
	}
}

void		sort5(t_stack **head)
{
	t_stack *a;

	a = NULL;
	pb(head, &a);
	pb(head, &a);
	ss(head, &a);
	ra(head);
	ra(head);
	pa(&a, head);
	pa(&a, head);
	ra(head);
	ra(head);
}

void		sort4(t_stack **head)
{
	t_stack *a;

	a = NULL;
	pb(head, &a);
	sort3(head);
	pa(&a, head);
	add_index_mark(head);
	if ((*head)->markup == 1)
		sa(head);
	else if ((*head)->markup == 2)
	{
		rra(head);
		sa(head);
		ra(head);
		ra(head);
	}
	else if ((*head)->markup == 3)
		ra(head);
}

void		sort3(t_stack **head)
{
	if ((*head)->index > (*head)->next->index && (*head)->index > (*head)->next->next->index)
		ra(head);
	if ((*head)->index > (*head)->next->index)
		sa(head);
}

void		go_lastchunk(t_stack **a, t_stack **b, int max)
{
	int 		i;

	i = max - 1;
	while (len_stk(*a) != 1)
	{
		if ((*a)->index == i)
			ra(a);
		else
			pb(a, b);
	}
}