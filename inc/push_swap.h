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

# define RED			"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define EOC			"\033[0m"
#define CHANK_100 5
#define CHANK_500 11

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
t_stack	*last_list_ps(t_stack *head);
/*
 * print
 */
void		print_list_ps(t_stack *a, t_stack *b);

/*
 * cheak.c
 */
int 		check_is_number(char *str);
int 		check_duplicate(t_stack *head, int nbr);
int 		cheak_chank(t_stack *head, int chunk);
int 	cheak_chank_mark(t_stack *head, int chunk);
int 		cheak_mark(t_stack *head);
int 		cheak_sort(t_stack *head);
int 		cheak_backsort(t_stack *head);

/////////////
int 	add_index(t_stack *head);
int 	add_index_mark(t_stack **head);
int 	mark_index(t_stack *head);
int 	mark_index2(t_stack *head);
void		push(t_stack **out, t_stack **in);
void		rotate(t_stack **head);
void		rev_rotate(t_stack **head);
void		swap(t_stack **head);
void		go_lastchunk(t_stack **a, t_stack **b, int max);
int 	len_stk(t_stack *head);
void		go_outb_up(t_stack **a, t_stack **b, int i);
void		go_outb_down(t_stack **a, t_stack **b, int i);
int 		up_or_down(t_stack *b, int i);

void		sort3(t_stack **head);
void		sort4(t_stack **head);

#endif