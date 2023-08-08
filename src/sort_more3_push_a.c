/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more3_push_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:42 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/07 16:47:59 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotating_a(t_list **stack_a)
{
	int	size;
	int	position;

	position = check_position(*stack_a, find_min(*stack_a));
	size = ft_lstsize(*stack_a);
	while ((*stack_a)->content != find_min(*stack_a))
	{
		if (position > size / 2)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
}

void	sort_min_max(t_list **stack_a, t_list **stack_b, int size)
{
	int	position;

	position = check_position(*stack_a, find_min(*stack_a));
	while ((*stack_a)->content != find_min(*stack_a))
	{
		if (position > size / 2)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'a');
}

void	sort_btw_min_max(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*temp_a;
	int		position;
	int		target;

	target = find_max(*stack_a);
	temp_a = *stack_a;
	while (temp_a != NULL)
	{
		if (target > temp_a->content && temp_a->content > (*stack_b)->content)
			target = temp_a->content;
		temp_a = temp_a->next;
	}
	position = check_position(*stack_a, target);
	while ((*stack_a)->content != target)
	{
		if (position > size / 2)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'a');
}

void	put_all_a(t_list **stack_a, t_list **stack_b)
{
	int		size;

	while (*stack_b != NULL)
	{
		size = ft_lstsize(*stack_a);
		if ((*stack_b)->content > find_max(*stack_a)
			|| (*stack_b)->content < find_min(*stack_a))
			sort_min_max(stack_a, stack_b, size);
		else if ((*stack_b)->content < find_max(*stack_a)
			&& (*stack_b)->content > find_min(*stack_a))
			sort_btw_min_max(stack_a, stack_b, size);
	}
}
