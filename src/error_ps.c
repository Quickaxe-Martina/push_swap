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

void	error_ps(int error)
{
	if (error == 1)
	{
		dprintf(2, "push_swap: malloc error\n");/////////
		exit(1);
	}
	else if (error == 2)
	{
		dprintf(2, "push_swap: not a number\n");/////////
		exit(1);
	}
	else if (error == 3)
	{
		dprintf(2, "push_swap: have dublicate\n");/////////
		exit(1);
	}
}