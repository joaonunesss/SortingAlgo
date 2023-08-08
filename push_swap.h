/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:47:10 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/03 14:26:39 by jmarinho         ###   ########.fr       */
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

void	check_av(char **av, int flag);
void	check_duplicates(t_list *stack);
void	check_integer_limits(t_list *stack_a);
t_list	*stack_init(char **av, int flag);
int		ft_num_words_count(char const *s, char c);
void	exit_error(void);
int		check_sort(t_list *stack_a);
void	free_list(t_list **lst, int flag);
void	free_array(char *array[], int ac);
void	rotating_a(t_list **stack_a);
void	srt_stacks(t_list **st_a, t_list **st_b, t_info nbr2srt, t_info tgt);
void	put_all_a(t_list **stack_a, t_list **stack_b);
t_info	find_nbr2move(t_list *stack_a, t_list *stack_b, t_info info_a);
int		mv_calcs(t_info info_a, t_info info_b);
void	check_errors(char *nbr, t_list **stack_a);
int		check_position(t_list *list, int target);
int		find_min(t_list *list);
int		find_max(t_list *list);
t_info	find_target_in_b(t_list *b, int content_a);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);	
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_more(t_list **stack_a, t_list **stack_b);
int		find_min_index(t_list **stack_a);
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
#endif
