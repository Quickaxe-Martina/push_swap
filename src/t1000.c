/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t1000.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:48:56 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/11 18:48:58 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_list_ps(t_stack *a, t_stack *b)
{
	ft_dprintf(1, "***************************\n");
	while (1)
	{
		if (a)
			ft_dprintf(1, "*%-10d\t", a->nbr);
		else
			ft_dprintf(1, "*%s\t", "          ");
		if (b)
			ft_dprintf(1, "%10d*\n", b->nbr);
		else
			ft_dprintf(1, "%s*\n", "          ");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		if ((!a) && !b)
			break ;
	}
	ft_dprintf(1, "*A                       B*\n");
	ft_dprintf(1, "***************************\n");
}

void	chunk_2_pushup(t_stack **a, t_stack **b, t_chunk p)
{
	while (!cheak_chank2(*a, p.end1 - p.chunk, p.end1) ||
			!cheak_chank2(*a, p.end2 - p.chunk, p.end2))
	{
		if ((*a)->index >= p.end1 - p.chunk && (*a)->index <= p.end1)
			pb(a, b);
		else if ((*a)->index >= p.end2 - p.chunk && (*a)->index <= p.end2)
		{
			pb(a, b);
			rb(b);
		}
		else
			ra(a);
	}
}

void	size_chunk(t_chunk *p, int size)
{
	if (size >= 500)
	{
		p->chunk = size / CHANK_500;
		p->i = CHANK_500 / 2 + 1;
	}
	else if (size >= 25 && size < 500)
	{
		p->chunk = size / CHANK_100;
		p->i = CHANK_100 / 2 + 1;
	}
	else
	{
		p->chunk = size / CHANK_ELSE;
		p->i = CHANK_ELSE / 2 + 1;
	}
	p->j = p->i + 1;
}

void	chunk_2(t_stack **a, t_stack **b, int size)
{
	t_chunk		p;

	size_chunk(&p, size);
	p.end1 = p.chunk * p.i;
	p.end2 = p.chunk;
	chunk_2_pushup(a, b, p);
	p.i--;
	while (p.i > 1)
	{
		p.end1 = p.j * p.chunk;
		p.end2 = p.i * p.chunk;
		chunk_2_pushup(a, b, p);
		p.i--;
		p.j++;
	}
}

void	ft_del_arr(char ***arr)
{
	int	i;

	i = -1;
	if (!(*arr))
		return ;
	while ((*arr)[++i])
		free((*arr)[i]);
	if (*arr)
		free(*arr);
	*arr = NULL;
}
