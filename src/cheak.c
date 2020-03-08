/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:06:13 by qmartina          #+#    #+#             */
/*   Updated: 2020/02/15 22:06:14 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int 	check_is_number(char *str)
{
	int		i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			;
		else
			return (0);
	}
	return (1);
}

int 	check_duplicate(t_stack *head, int nbr)
{
	t_stack		*q;

	if (!head)
		return (-404);
	q = head;
	while (q->next)
	{
		if (q->nbr == nbr)
			return (0);
		q = q->next;
	}
	return (1);
}

int 	cheak_backsort(t_stack *head)
{
	t_stack *q;

	q = head;
	while (q && q->next)
	{
		if (q->nbr < q->next->nbr)
			return (0);
		q = q->next;
	}
	return (1);
}

int 	cheak_sort(t_stack *head)
{
	t_stack *q;

	q = head;
	while (q && q->next)
	{
		if (q->nbr > q->next->nbr)
			return (0);
		q = q->next;
	}
	return (1);
}

int 	cheak_chank(t_stack *head, int chunk)
{
	t_stack *q;

	q = head;
	while (q && q->next)
	{
		if (q->index < chunk)
			return (0);
		q = q->next;
	}
	return (1);
}

int 	cheak_chank_mark(t_stack *head, int chunk)
{
	t_stack *q;

	q = head;
	while (q && q->next)
	{
		if (q->markup < chunk)
			return (0);
		q = q->next;
	}
	return (1);
}

int 	cheak_mark(t_stack *head)
{
	t_stack *q;

	q = head;
	while (q && q->next)
	{
		if (q->markup == 0)
			return (0);
		q = q->next;
	}
	return (1);
}
