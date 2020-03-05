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

void		push(t_stack **out, t_stack **in)
{
	t_stack	*tmp;

	if (*out == NULL)
		return ;
	tmp = *out;
	*out = (*out)->next;
	tmp->next = *in;
	*in = tmp;
	write(1, "push\n", 5);
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
	write(1, "rotate\n", 7);
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
	ft_putendl("rev_rotate");
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
	write(1, "swap\n", 5);
//	print_list_ps(a, NULL);
}