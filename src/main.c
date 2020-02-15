/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:26:33 by qmartina          #+#    #+#             */
/*   Updated: 2020/02/15 20:26:40 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_list_ps(t_stack *a, t_stack *b)
{
	dprintf(1, "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	while (a && b)
	{
		if (a->flag != 0)
			dprintf(1, "\\\\\t%d\t", a->nbr);
		else
			dprintf(1, "\\\\\t_\t");
		if (b->flag != 0)
			dprintf(1, "%d\t\\\\\\\n", b->nbr);
		else
			dprintf(1, "_\t\\\\ind: %d; mark: %d\n", a->index, a->markup);
		a = a->next;
		b = b->next;
	}
	dprintf(1, "\\\\\ta\tb\t\\\\\n");
	dprintf(1, "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int 		i;

	i = 0;
	a = NULL;
	b = NULL;
	while (++i < argc)
	{
		if (!check_is_number(argv[i]))
		{
			free_list_ps(a, b);
			error_ps(2);
		}
		a = add_list_ps(a, ft_atoi(argv[i]), 1);
		if (!check_duplicate(a, ft_atoi(argv[i])))
		{
			free_list_ps(a, b);
			error_ps(3);
		}
		b = add_list_ps(b, 0, 0);
	}
	add_index(a);
	mark_index(a);
	print_list_ps(a, b);
	free_list_ps(a, b);
	return (0);
}
