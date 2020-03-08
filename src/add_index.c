/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:31:51 by qmartina          #+#    #+#             */
/*   Updated: 2020/02/15 22:31:53 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int 	add_index(t_stack *head)
{
	t_stack		*q;
	t_stack		*tmp;
	int 		i;
	int 		flag;

	i = 0;
	while (1)
	{
		flag = 0;
		tmp = head;
		while (tmp->next && tmp->index != -1)
			tmp = tmp->next;
		q = head;
		while (q)
		{
//			printf("tmp: %d\tq: %d\n", tmp->nbr, q->nbr);
			if (tmp->nbr > q->nbr && q->index == -1)
			{
				tmp = q;
				q = head;
				flag = 1;
			}
			else
				q = q->next;
		}
		if (flag == 0 && tmp->index != -1)
			break ;
		tmp->index = i;
		i++;
	}
	return (i);
}

int 	add_index_mark(t_stack **head)
{
	t_stack		*q;
	t_stack		*tmp;
	int 		i;
	int 		flag;

	i = 0;
	q = *head;
	while (q)
	{
		q->markup = -1;
		q = q->next;
	}
	while (1)
	{
		flag = 0;
		tmp = *head;
		while (tmp->next && tmp->markup != -1)
			tmp = tmp->next;
		q = *head;
		while (q)
		{
//			printf("tmp: %d\tq: %d\n", tmp->nbr, q->nbr);
			if (tmp->nbr > q->nbr && q->markup == -1)
			{
				tmp = q;
				q = *head;
				flag = 1;
			}
			else
				q = q->next;
		}
		if (flag == 0 && tmp->markup != -1)
			break ;
		tmp->markup = i;
		i++;
	}
	return (i);
}