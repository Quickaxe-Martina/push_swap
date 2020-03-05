/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:26:41 by qmartina          #+#    #+#             */
/*   Updated: 2020/02/15 23:26:43 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int 	mark_index(t_stack *head)
{
	t_stack		*q;

	q = head;
	while (q && q->next)
	{
		if ((q->next->index - q->index) >= 1)
			q->markup = 1;
		else
			q->markup = 0;
		q = q->next;
	}
	q->markup = 0;
	return (1);
}

int 	mark_index2(t_stack *head)
{
	t_stack		*q;
	int 		len;

	q = head;
	len = 0;
	while (q && q->next)
	{
		if ((q->next->index - q->index) == 1 || len == q->index)
			q->markup = 1;
		else
			q->markup = 0;
		q = q->next;
		len++;
	}
	if (len == q->index)
		q->markup = 1;
	else
		q->markup = 0;
	return (1);
}