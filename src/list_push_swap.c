/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:35:29 by qmartina          #+#    #+#             */
/*   Updated: 2020/02/15 21:35:31 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack		*add_list_ps(t_stack *head, int nbr, int flag)
{
	t_stack		*new;
	t_stack 	*q;

	if (head == NULL)
	{
		if (!(new = (t_stack *)malloc(sizeof(t_stack))))
			error_ps(1, NULL);
		new->nbr = nbr;
		new->flag = flag;
		new->index = -1;
		new->markup = -1;
		new->next = NULL;
		return (new);
	}
	q = head;
	while (head->next)
		head = head->next;
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error_ps(1, NULL);
	new->nbr = nbr;
	new->flag = flag;
	new->index = -1;
	new->markup = -1;
	new->next = NULL;
	head->next = new;
	return (q);
}

t_stack	*last_list_ps(t_stack *head)
{
	t_stack *q;

	q = head;
	while (q && q->next)
		q = q->next;
	return (q);
}

int 	free_list_ps(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	*a = NULL;
	return (0);
}