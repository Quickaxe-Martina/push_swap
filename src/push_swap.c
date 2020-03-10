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
	ft_dprintf(1, "**************************************\n");
	while (1)
	{
		if (a && a->flag != 0)
			ft_dprintf(1, "%-4d\t", a->nbr);
		else
			ft_dprintf(1, "____\t");
		if (b && b->flag != 0)
			ft_dprintf(1, "%-4d\n", b->nbr);
		else
			ft_dprintf(1, "_____\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		if ((!a) && !b)
			break ;
	}
	ft_dprintf(1, "A\t\t\t\tB\n");
	ft_dprintf(1, "**************************************\n");
}

int 	len_stk(t_stack *head)
{
	t_stack *q;
	int 	i;

	i = 0;
	q = head;
	if (head == NULL)
		return (0);
	while (q)
	{
		q = q->next;
		i++;
	}
	return (i);
}

void	chunk_2_pushup(t_stack **a, t_stack **b, int end1, int end2, int chunk)
{
	while (!cheak_chank2(*a, end1 - chunk, end1) || !cheak_chank2(*a, end2 - chunk, end2))
	{
		if ((*a)->index >= end1 - chunk && (*a)->index <= end1)
			pb(a, b);
		else if ((*a)->index >= end2 - chunk && (*a)->index <= end2)
		{
			pb(a, b);
			rb(b);
		}
		else
			ra(a);
	}
}

void	chunk_2(t_stack **a, t_stack **b, int size)
{
	int 		chunk;
	int 		i;
	int 		j;

	chunk = (size < 500) ? size / CHANK_100 : size / CHANK_500;
	i = (size < 500) ? CHANK_100 / 2 + 1 : CHANK_500 / 2 + 1;
	j = i + 1;
	chunk_2_pushup(a, b, chunk * i, chunk, chunk);
	i--;
	while (i > 1)
	{
		chunk_2_pushup(a, b, j * chunk, i * chunk, chunk);
		i--;
		j++;
	}
}

void	ft_del_arr(char ***arr)
{
	int	i;

	i = -1;
	if (!(*arr))
		return ;
	while((*arr)[++i])
		free((*arr)[i]);
	if (*arr)
		free(*arr);
	*arr = NULL;
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int 		i;
	int 		j;
	char 		**str;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc <= 1)
		error_ps(5, NULL);
	while (++i < argc)
	{
		str = ft_strsplit(argv[i], ' ');
		j = -1;
		while (str[++j])
		{
			if (!check_is_number(str[j]))
				error_ps(2, &a);
			a = add_list_ps(a, ft_atoi(str[j]), 1);
			if (!(cheak_max_min(str[j], ft_atoi(str[j]))))
				error_ps(4, &a);
			if (!check_duplicate(a, ft_atoi(str[j])))
				error_ps(3, &a);
		}
		ft_del_arr(&str);
	}
	i = add_index(a);
	chunk_2(&a, &b, i);
	go_lastchunk(&a, &b, i);
	while (!cheak_sort(a) || len_stk(b) > 0)
	{
		i = a->index - 1;
		up_or_down(b, i) ? go_outb_up(&a, &b, i) : go_outb_down(&a, &b, i);
	}
	return (free_list_ps(&a));
}
