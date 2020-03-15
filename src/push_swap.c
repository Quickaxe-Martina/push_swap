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
		error_ps(5, a);
}

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	a = NULL;
	b = NULL;
	add_stk(&a, argc, argv);
	i = add_index(a);
	if (i == 3 && !cheak_sort(a))
		return (sort3(&a) && free_list_ps(&a) ? 1 : 0);
	else if (i == 2 && !cheak_sort(a))
		return (sort2(&a) && free_list_ps(&a) ? 1 : 0);
	else if (i <= 5 && !cheak_sort(a))
		return (sort5(&a, &b, i) && free_list_ps(&a) ? 1 : 0);
	else if (cheak_sort(a))
		return (free_list_ps(&a));
	chunk_2(&a, &b, i);
	go_lastchunk(&a, &b, i);
	while (!cheak_sort(a) || len_stk(b) > 0)
	{
		i = a->index - 1;
		up_or_down(b, i) ? go_outb_up(&a, &b, i) : go_outb_down(&a, &b, i);
	}
	return (free_list_ps(&a));
}
