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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define EOC		"\033[0m"
# define CHANK_100	5
# define CHANK_500	15
# define CHANK_ELSE	3

typedef struct		s_stack
{
	int				nbr;
	int				index;
	int				markup;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_chunk
{
	int				chunk;
	int				i;
	int				j;
	int				end1;
	int				end2;
}					t_chunk;

typedef struct		s_sort
{
	int				f;
	int				k;
	int				w;
	int				ok;
}					t_sort;

void				error_ps(int error, t_stack **a);
t_stack				*add_list_ps(t_stack *head, int nbr);
int					free_list_ps(t_stack **a);
t_stack				*last_list_ps(t_stack *head);
void				print_list_ps(t_stack *a, t_stack *b);
int					check_is_number(char *str);
int					check_duplicate(t_stack *head, int nbr);
int					cheak_sort(t_stack *head);
int					cheak_chank2(t_stack *head, int start, int end);
int					cheak_max_min(char *str, int nbr);
int					add_index(t_stack *head);
int					add_index_mark(t_stack **head);
void				pa(t_stack **b, t_stack **a);
void				pb(t_stack **a, t_stack **b);
void				push(t_stack **out, t_stack **in);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rotate(t_stack **head);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rev_rotate(t_stack **head);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				swap(t_stack **head);
void				go_lastchunk(t_stack **a, t_stack **b, int max);
int					len_stk(t_stack *head);
void				go_outb_up(t_stack **a, t_stack **b, int i);
void				go_outb_down(t_stack **a, t_stack **b, int i);
int					up_or_down(t_stack *b, int i);
int					sort3(t_stack **a);
int					sort5(t_stack **a, t_stack **b, int i);
int					sort2(t_stack **a);
void				ft_del_arr(char ***arr);
void				chunk_2(t_stack **a, t_stack **b, int size);
int					is_vseok(t_stack *b, int i);
int					find_i(t_stack **b, int i, int j);
t_stack				*find_i_down(t_stack **b, int i, int j);
int					is_vseok_down(t_stack *b, int i);

#endif
