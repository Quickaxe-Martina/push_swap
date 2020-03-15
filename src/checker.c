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

void			go_read2(t_stack **a, t_stack **b, char *s)
{
	if (ft_strequ("ra", s))
		rotate(a);
	else if (ft_strequ("rb", s))
		rotate(b);
	else if (ft_strequ("rr", s))
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strequ("rra", s))
		rev_rotate(a);
	else if (ft_strequ("rrb", s))
		rev_rotate(b);
	else if (ft_strequ("rrr", s))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
	{
		ft_dprintf(2, RED"Error\n"EOC);
		exit(1);
	}
}

void			go_read(t_stack **a, t_stack **b)
{
	char		*s;

	while (get_next_line(0, &s) > 0)
	{
		if (*s == '\0')
			continue ;
		else if (ft_strequ("sa", s))
			swap(a);
		else if (ft_strequ("sb", s))
			swap(b);
		else if (ft_strequ("ss", s))
		{
			swap(a);
			swap(b);
		}
		else if (ft_strequ("pa", s))
			push(b, a);
		else if (ft_strequ("pb", s))
			push(a, b);
		else
			go_read2(a, b, s);
		free(s);
	}
}

void			add_stk(t_stack **a, int argc, char **argv)
{
	int			i;
	int			j;
	char		**str;

	i = 0;
	while (++i < argc)
	{
		if (!(str = ft_strsplit(argv[i], ' ')))
			continue ;
		j = -1;
		while (str[++j])
		{
			if (!check_is_number(str[j]))
				error_ps(2, a);
			*a = add_list_ps(*a, ft_atoi(str[j]));
			if (!(cheak_max_min(str[j], ft_atoi(str[j]))))
				error_ps(4, a);
			if (!check_duplicate(*a, ft_atoi(str[j])))
				error_ps(3, a);
		}
		ft_del_arr(&str);
	}
	if (argc <= 1 || len_stk(*a) == 0)
		exit(1);
}

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	add_stk(&a, argc, argv);
	go_read(&a, &b);
	if (cheak_sort(a) && len_stk(b) == 0)
		ft_dprintf(1, GREEN"OK\n"EOC);
	else
		ft_dprintf(1, RED"KO\n"EOC);
	return (free_list_ps(&a) + free_list_ps(&b));
}
