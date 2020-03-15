/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:25:43 by qmartina          #+#    #+#             */
/*   Updated: 2019/05/02 13:21:09 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

static int			ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int					ft_atoi(const char *str)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str != '\0') && ft_is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
		if (result > 2147483647 && sign == 1)
			return (-1);
		else if (result > 2147483648 && sign == -1)
			return (0);
	}
	return ((int)(result * sign));
}
