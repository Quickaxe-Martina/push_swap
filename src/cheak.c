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