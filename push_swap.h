/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:47:10 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/01 19:05:10 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "lib/libft/libft.h"

typedef struct info
{
	int		size;
	int		rotations;
	long	content;
}				t_info;

// //moves.c
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
//aux.c
void	exit_error();
int		check_sort(t_list *stack_a);
int		ft_min_index(t_list **stack_a);
void	free_list(t_list **lst, int flag);
void	free_array(char *array[]);
//sort_big.c
void	sort_more(t_list **stack_a, t_list **stack_b);
void	rotating_a(t_list **stack_a);
//sort_big2.c
void	sort(t_list **stack_a, t_list **stack_b, t_info nbr2sort, t_info target);
//sort_big3.c
void	put_all_a(t_list **stack_a, t_list **stack_b);
//strat.c
t_info	find_nbr2move(t_list *stack_a, t_list *stack_b, t_info info_a);
//strat2.c
int		mv_calcs(t_info info_a, t_info info_b);
//check_errors.c
int	checker_and_fill(char *str, t_list **stack_a);
//sort_utils.c
int		check_position(t_list *list, int target);
int		min(t_list *list);
int		max(t_list *list);
t_info	b_target(t_list *b, int content_a);
//sort_2_3.c
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);	
//sort_4_5.c
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		target(t_list **stack_a);
#endif
