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
	dprintf(1, YELLOW"**************************************\n"EOC);
	while (1)
	{
		if (a && a->flag != 0)
			dprintf(1, "%s%-4d%s; ind: %-3d; mark: %d;\t", GREEN, a->nbr, EOC, a->index, a->markup);
		else
			dprintf(1, "________________________\t");
		if (b && b->flag != 0)
			dprintf(1, "%s%-4d%s; ind: %-3d\n", GREEN, b->nbr, EOC, b->index);
		else
			dprintf(1, "_____\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		if ((!a) && !b)
			break ;
	}
	dprintf(1, "A\t\t\t\tB\n");
	dprintf(1, YELLOW"**************************************\n"EOC);
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

int 	len_stk(t_stack *head)
{
	t_stack *q;
	int 	i;

	i = 0;
	q = head;
	while (q)
	{
		q = q->next;
		i++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int 		i;
	int 		chunk;

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
	}
	i = add_index(a);
	chunk = (i < 500) ? i / 4 : i / 20;/////////////////
	while (chunk < i)
	{
		while (!cheak_chank(a, chunk))
		{
			if (a->index < chunk)
				push(&a, &b);
			else
				rotate(&a);
		}
		chunk += (i < 500) ? i / 4 : i / 20;////////////////////
	}
//	print_list_ps(a, b);
	go_lastchunk(&a, &b, i);
	while (!cheak_sort(a) || b)
	{
		i = a->index - 1;
//		printf("i= %d\n", i);
		up_or_down(b, i) ? go_outb_up(&a, &b, i) : go_outb_down(&a, &b, i);
	}
	if (cheak_sort(a) && len_stk(b) == 0)
		ft_putstr(GREEN"OK"EOC);
	else
		ft_putstr(RED"KO"EOC);
//	print_list_ps(a, b);
	return (0);
}
