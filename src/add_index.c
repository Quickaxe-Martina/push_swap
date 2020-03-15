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

t_stack			*tmp_point(t_stack *head)
{
	t_stack		*tmp;

	tmp = head;
	while (tmp->next && tmp->index != -1)
		tmp = tmp->next;
	return (tmp);
}

int				add_ind2(t_stack *head, t_stack **tmp, t_stack **q)
{
	*tmp = *q;
	*q = head;
	return (1);
}

int				add_index(t_stack *head)
{
	t_stack		*q;
	t_stack		*tmp;
	int			i;
	int			flag;

	i = 0;
	while (1)
	{
		flag = 0;
		tmp = tmp_point(head);
		q = head;
		while (q)
		{
			if (tmp->nbr > q->nbr && q->index == -1)
				flag = add_ind2(head, &tmp, &q);
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
