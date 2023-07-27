/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:47:10 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/27 16:46:40 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "lib/libft/libft.h"

typedef struct info_a
{
	int	rotations_a;
	int	size_a;
}				t_info_a;

typedef struct info_b
{
	int	rotations_b;
	int	size_b;
}				t_info_b;

typedef struct nbr_info
{
	long	content;
	int		rotations;
	int		size_list;
}					t_nbr_info;

int		check_sort(t_list *stack_a);
//aux.c
void	exit_error(t_list **stack_a);
int		ft_min_index(t_list **stack_a);
//simple_sort.c
void	simple_sort_5(t_list **stack_a, t_list **stack_b, int arg);
void	top_five(t_list **stack_a, t_list **stack_b, int min_index);
void	top_four(t_list **stack_a, t_list **stack_b, int i);
void	simple_sort_3(t_list **stack_a, int arg);
void	simple_sort_3_aux(t_list **stack_a, int a, int b);
//check_errors.c
void	checker_and_fill(char *str, t_list **stack_a);
// //swaps.c
//swap the first 2 elements at the top of stack a.   
void	swap(t_list **stack_a, char c);
//sa and sb at the same time
void	swap_both(t_list **stack_a, t_list **stack_b);
//Take the first element at the top of b and put it at the top of a
void	push(t_list **stack_a, t_list **stack_b, char c);
//The first element becomes the last one.
void	rotate(t_list **stack_a, char c);
//ra and rb at the same time.
void	rotate_both(t_list **stack_a, t_list **stack_b);
//The last element becomes the first one.
void	reverse_rotate(t_list **stack_a, char c);
//rra and rrb at the same time.
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
//printing.c
void	printlinkedlist(t_list *head);
void	freelinkedlist(t_list *head);
//sort_big.c
void	sort_more(t_list **stack_a, t_list **stack_b);
void	rotating_a(t_list **stack_a);
//outras
void	sort(t_list **stack_a, t_list **stack_b, t_nbr_info nbr2sort, t_nbr_info target);
void	put_all_a(t_list **stack_a, t_list **stack_b);
int	target(t_list **stack_a, int min_t);
int	mv_calcs(t_info_a info_a, t_info_b info_b);
t_nbr_info	a_nbr2move(t_list *stack_a, t_list *stack_b, t_info_a info_a);
int	check_position(t_list *list, int target);
int	min(t_list *list);
int	max(t_list *list);
t_nbr_info	b_target(t_list *b, int content_a);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
#endif
