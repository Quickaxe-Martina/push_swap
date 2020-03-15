/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:07:01 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/12 20:07:03 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		pa(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void		pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}

void		ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void		rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void		rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
