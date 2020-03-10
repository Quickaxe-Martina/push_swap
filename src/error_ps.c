/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:38:03 by qmartina          #+#    #+#             */
/*   Updated: 2020/02/15 21:38:04 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_ps(int error, t_stack **a)
{
	if (*a)
		free_list_ps(a);
	if (error == 1)
	{
		ft_dprintf(2, "push_swap: malloc error\n");/////////
		exit(1);
	}
	else if (error == 2)
	{
		ft_dprintf(2, "push_swap: not a number\n");/////////
		exit(1);
	}
	else if (error == 3)
	{
		ft_dprintf(2, "push_swap: have a dublicate\n");/////////
		exit(1);
	}
	else if (error == 4)
	{
		ft_dprintf(2, "push_swap: number is not int\n");/////////
		exit(1);
	}
	else if (error == 5)
	{
		ft_dprintf(2, "push_swap: no arguments\n");
		exit(1);
	}
}