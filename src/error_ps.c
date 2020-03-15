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
	error = 1;
	ft_dprintf(STDERR_FILENO, RED"Error\n"EOC);
	exit(1);
}
