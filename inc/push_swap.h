/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:25:13 by qmartina          #+#    #+#             */
/*   Updated: 2020/02/15 20:25:14 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct		s_stack
{
	int 			nbr;
	int 			index;
	int 			markup;
	int 			flag;
	struct s_stack	*next;
}					t_stack;

/*
 * error
*/
void		error_ps(int error);

/*
 * list
*/
t_stack		*add_list_ps(t_stack *head, int nbr, int flag);
int 		free_list_ps(t_stack *a, t_stack *b);
/*
 * print
 */
void		print_list_ps(t_stack *a, t_stack *b);

/*
 * cheak
 */
int 		check_is_number(char *str);
int 		check_duplicate(t_stack *head, int nbr);

/////////////
int 	add_index(t_stack *head);
int 	mark_index(t_stack *head);

#endif