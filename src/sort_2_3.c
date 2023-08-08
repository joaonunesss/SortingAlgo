/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:32:29 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/07 16:47:47 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	if_min_on_top(t_list **stack_a)
{
	if ((*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
}

void	if_min_in_mid(t_list **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->next->content)
		swap(stack_a, 'a');
	else
		rotate(stack_a, 'a');
}

void	if_min_in_last(t_list **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->content)
		reverse_rotate(stack_a, 'a');
	else
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

void	sort_three(t_list **stack_a)
{
	int	small;

	small = find_min(*stack_a);
	if ((*stack_a)->content == small)
		if_min_on_top(stack_a);
	if ((*stack_a)->next->content == small)
		if_min_in_mid(stack_a);
	if ((*stack_a)->next->next->content == small)
		if_min_in_last(stack_a);
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 'a');
}
