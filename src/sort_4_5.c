/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:23:51 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/08 13:12:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	srt_index_4(t_list **stack_a, t_list **stack_b, int index)
{
	if (index == 0)
		push(stack_b, stack_a, 'b');
	else if (index == 1)
	{
		rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return (EXIT_SUCCESS);
		push(stack_b, stack_a, 'b');
	}
	else if (index == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return (EXIT_SUCCESS);
		push(stack_b, stack_a, 'b');
	}
	else if (index == 3)
	{
		reverse_rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return (EXIT_SUCCESS);
		push(stack_b, stack_a, 'b');
	}
	return (EXIT_FAILURE);
}

bool	srt_index_5(t_list **stack_a, t_list **stack_b, int index)
{
	if (index <= 2)
		srt_index_4(stack_a, stack_b, index);
	else if (index == 3)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return (EXIT_SUCCESS);
		push(stack_b, stack_a, 'b');
	}
	else if (index == 4)
	{
		reverse_rotate(stack_a, 'a');
		if (!check_sort(*stack_a))
			return (EXIT_SUCCESS);
		push(stack_b, stack_a, 'b');
	}
	return (EXIT_FAILURE);
}

int	find_min_index(t_list **stack_a)
{
	t_list	*temp;
	int		index;
	int		small;

	index = 0;
	temp = *stack_a;
	small = find_min(*stack_a);
	while (temp->content != small)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = find_min_index(stack_a);
	if (!srt_index_4(stack_a, stack_b, index))
		return ;
	sort_three(stack_a);
	push(stack_a, stack_b, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = find_min_index(stack_a);
	srt_index_5(stack_a, stack_b, i);
	i = find_min_index(stack_a);
	if (!check_sort(*stack_a))
		return ;
	srt_index_4(stack_a, stack_b, i);
	sort_three(stack_a);
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
}
