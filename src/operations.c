/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:05:13 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/04 19:05:14 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		pa(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void		pb(t_stack **a, t_stack **b)
{
	push(a, b);

	ft_putendl_fd("pb", 1);
}

void		push(t_stack **out, t_stack **in)
{
	t_stack	*tmp;

	if (*out == NULL)
		return ;
	tmp = *out;
	*out = (*out)->next;
	tmp->next = *in;
	*in = tmp;
}

void		ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void		rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void		rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}

void		rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*a;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	a = *head;
	tmp = *head;
	*head = (*head)->next;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = a;
	a->next = NULL;
}

void		rra(t_stack **a)
{
	rev_rotate(a);
	ft_putendl_fd("rra", 1);
}

void		rrb(t_stack **b)
{
	rev_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void		rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("rrr", 1);
}

void		rev_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*a;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	a = tmp;
	tmp = tmp->next;
	a->next = NULL;
	tmp->next = *head;
	*head = tmp;
}

void		sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void		sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void		ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}

void		swap(t_stack **head)
{
	t_stack	*a;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	a = *head;
	*head = (*head)->next;
	a->next = (*head)->next;
	(*head)->next = a;
}