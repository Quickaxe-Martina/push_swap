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
	while (tmp->index != i)
	{
		k++;
		tmp = tmp->next;
	}
	if (k < len_stk(b) - k + 1)
		return (1);
	return (0);
}

void		go_outb_up(t_stack **a, t_stack **b, int i)
{
	while ((*b)->index != i && (*b)->index != i - 1)
		rotate(b);
	if ((*b)->index == i - 1)
	{
		push(b, a);
		while ((*b)->index != i)
			rotate(b);
		push(b, a);
		swap(a);
	}
	else
		push(b, a);
}

void		go_outb_down(t_stack **a, t_stack **b, int i)
{
	t_stack *last;

//	ft_putstr(RED"START\n");
	last = last_list_ps(*b);
	while (last->index != i && last->index != i - 1)
	{
		rev_rotate(b);
		last = last_list_ps(*b);
	}
	if (last->index == i - 1)
	{
		rev_rotate(b);
		push(b, a);
		last = last_list_ps(*b);
		while (last->index != i)
		{
			rev_rotate(b);
			last = last_list_ps(*b);
		}
		rev_rotate(b);
		push(b, a);
		swap(a);
	}
	else
	{
		rev_rotate(b);
		push(b, a);
	}
//	ft_putstr("END\n"EOC);
}


void		sort4(t_stack **head)
{
	swap(head);
	rev_rotate(head);
	rev_rotate(head);
	swap(head);
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
	int 		min;
	int 		l;
	int 		i;

	min = ((max / 4) * 3) + (max % 4);/////////
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
//	else if (len_stk(*a) == 5)
//		sort3(a);
//	printf(RED"i = %d\n"EOC, i);
//	print_list_ps(*a, *b);
}