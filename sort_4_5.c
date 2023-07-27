/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:23:51 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/27 17:18:29 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_four(t_list **stack_a, t_list **stack_b, int i)
{
	if (i == 0)
		push(stack_b, stack_a, 'b');
	else if (i == 1)
	{
		rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return ;
		push(stack_b, stack_a, 'b');
	}
	else if (i == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return ;
		push(stack_b, stack_a, 'b');
	}
	else if (i == 3)
	{
		reverse_rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return ;
		push(stack_b, stack_a, 'b');
	}
}

void	top_five(t_list **stack_a, t_list **stack_b, int i)
{
	if (i <= 2)
		top_four(stack_a, stack_b, i);
	else if (i == 3)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return ;
		push(stack_b, stack_a, 'b');
	}
	else if (i == 4)
	{
		reverse_rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return ;
		push(stack_b, stack_a, 'b');
	}
}

int	target(t_list **stack_a, int min_t)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack_a;
	min_t = min(*stack_a);
	while (temp->content != min_t)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	min;

	if (!check_sort(*stack_a))
		return ;
	min = 0;
	i = target(stack_a, min);
	top_four(stack_a, stack_b, i);
	sort_three(stack_a);
	push(stack_a, stack_b, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		i;

	if (!check_sort(*stack_a))
		return ;
	min = 0;
	i = target(stack_a, min);
	top_five(stack_a, stack_b, i);
	i = target(stack_a, min);
	if (!check_sort(*stack_a))
		return ;
	top_four(stack_a, stack_b, i);
	sort_three(stack_a);
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
}
