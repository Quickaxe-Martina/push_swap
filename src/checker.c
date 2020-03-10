/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:04:26 by qmartina          #+#    #+#             */
/*   Updated: 2020/03/09 19:04:28 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int 		i;
	int 		j;
	char 		**str;

	i = 0;
	a = NULL;
	b = NULL:
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
	while (get_next_line(0, &(&str)) > 0)
	{
		if (ft_strequ("sa", *str))
			swap(&a);
		else if (ft_strequ("sb", *str))
			swap(&b);
		else if (ft_strequ("ss", *str))
		{
			swap(&a);
			swap(&b);
		}
		else if (ft_strequ("pa", *str))
			push(&b, &a);
		else if (ft_strequ("pb", *str))
			push(&a, &b);
		else if (ft_strequ("ra", *str))
			rotate(&a);
		else if (ft_strequ("rb", *str))
			rotate(&b);
		else if (ft_strequ("rr", *str))
		{
			rotate(&a);
			rotate(&b);
		}
		else if (ft_strequ("rra", *str))
			rev_rotate(&a);
		else if (ft_strequ("rrb", *str))
			rev_rotate(&b);
		else if (ft_strequ("rrr", *str))
		{
			rev_rotate(&a);
			rev_rotate(&b);
		}
		else
		{
			ft_dprintf(2, RED"checker: error\n"EOC);
			exit(1);
		}
	}
	return (0);
}