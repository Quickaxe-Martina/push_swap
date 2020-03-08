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

//	ft_putstr(RED"UP_OR_DOWN\n"EOC);
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
		rotate(b);
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
			push(b, a);
			rotate(a);
		}
		else if ((*b)->index == i - 2)
		{
			f = 1;
			push(b, a);
			rotate(a);
		}
		else if ((*b)->index == i - 1)
		{
			k = 1;
			push(b, a);
		}
		else if ((*b)->index == i)
		{
			push(b, a);
			if (k == 1)
				swap(a);
			if (f == 1)
				rev_rotate(a);
			if (w == 1)
			{
				rev_rotate(a);
				if ((*a)->index > (*a)->next->index)
					swap(a);
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
		rev_rotate(b);
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
			rev_rotate(b);
			push(b, a);
			rotate(a);
		}
		else if (last->index == i - 2)
		{
			f = 1;
			rev_rotate(b);
			push(b, a);
			rotate(a);
		}
		else if (last->index == i - 1)
		{
			k = 1;
			rev_rotate(b);
			push(b, a);
		}
		else if (last->index == i)
		{
			rev_rotate(b);
			push(b, a);
			if (k == 1)
				swap(a);
			if (f == 1)
				rev_rotate(a);
			if (w == 1)
			{
				rev_rotate(a);
				if ((*a)->index > (*a)->next->index)
					swap(a);
			}
			break ;
		}
	}
}

void		sort5(t_stack **head)
{
	t_stack *a;

	a = NULL;
	push(head, &a);
	push(head, &a);
	swap(head);
	swap(&a);
	rotate(head);
	rotate(head);
	push(&a, head);
	push(&a, head);
	rotate(head);
	rotate(head);
}

void		sort4(t_stack **head)
{
	t_stack *a;

	a = NULL;
	push(head, &a);
	sort3(head);
	push(&a, head);
	add_index_mark(head);
	if ((*head)->markup == 1)
		swap(head);
	else if ((*head)->markup == 2)
	{
		rev_rotate(head);
		swap(head);
		rotate(head);
		rotate(head);
	}
	else if ((*head)->markup == 3)
		rotate(head);
//	swap(head);
//	rev_rotate(head);
//	rev_rotate(head);
//	swap(head);
}

void		sort3(t_stack **head)
{
	if ((*head)->index > (*head)->next->index && (*head)->index > (*head)->next->next->index)
		rotate(head);
	if ((*head)->index > (*head)->next->index)
		swap(head);
}

void		go_lastchunk(t_stack **a, t_stack **b, int max)
{
	int 		l;
	int 		i;

	l = 0;
	i = max - 1;
//	printf("max= %d\nmin= %d\nl= %d\n", max, min, l);
//	exit(1);
	while (!cheak_backsort(*a))
	{
		while(*a && (*a)->index < i)
		{
			push(a, b);
			l++;
		}
		if (*a && (*a)->index == i && (max - i) < 5)
		{
			rotate(a);
			i--;
		}
		else if ((max - i) >= 5)
		{
			push(a, b);
			l++;
		}
	}
	if (len_stk(*a) == 2)
		swap(a);
	else if (len_stk(*a) == 3)
		sort3(a);
	else if (len_stk(*a) == 4)
		sort4(a);
	else if (len_stk(*a) == 5)
		sort5(a);
//	else if (len_stk(*a) == 5)
//		sort3(a);
//	printf(RED"i = %d\n"EOC, i);
//	print_list_ps(*a, *b);
}