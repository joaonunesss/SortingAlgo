/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:32:29 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/27 16:38:43 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_min(t_list **stack_a)
{
	if ((*stack_a)->next->next->content < (*stack_a)->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
}

void	middle_min(t_list **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->next->content)
		swap(stack_a, 'a');
	else
		rotate(stack_a, 'a');
}

void	last_min(t_list **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->content)
		reverse_rotate(stack_a, 'a');
	else
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
}

void	sort_three(t_list **stack_a)
{
	int	min_t;

	min_t = min(*stack_a);
	if ((*stack_a)->content == min_t)
	{
		top_min(stack_a);
	}
	if ((*stack_a)->next->content == min_t)
	{
		middle_min(stack_a);
	}
	if ((*stack_a)->next->next->content == min_t)
	{
		last_min(stack_a);
	}
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 'a');
}
