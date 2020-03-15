/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:08:30 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/12 20:08:31 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		rra(t_stack **a)
{
	rev_rotate(a);
	ft_putendl_fd("rra", 1);
}

void		rrb(t_stack **b)
{
	rev_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void		rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("rrr", 1);
}

void		sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void		sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}
