/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:47 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/27 14:53:49 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_top(t_list **stack_a, t_nbr_info nbr2sort)
{
	while ((*stack_a)->content != nbr2sort.content)
	{
		if (nbr2sort.rotations > nbr2sort.size_list / 2)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
}

void	b_top(t_list **stack_b, t_nbr_info target)
{
	while ((*stack_b)->content != target.content)
	{
		if (target.rotations > target.size_list / 2)
			reverse_rotate(stack_b, 'b');
		else
			rotate(stack_b, 'b');
	}
}

void	ab_top(t_list **stack_a, t_list **stack_b, t_nbr_info nbr2sort, t_nbr_info target)
{
	while ((*stack_a)->content != nbr2sort.content && (*stack_b)->content != target.content)
	{
		if (nbr2sort.rotations > nbr2sort.size_list / 2
			&& target.rotations > target.size_list / 2)
			reverse_rotate_both(stack_a, stack_b);
		else if (nbr2sort.rotations < nbr2sort.size_list / 2
			&& target.rotations > target.size_list / 2)
			rotate(stack_a, 'a');
		else if (target.rotations < target.size_list / 2
			&& nbr2sort.rotations > nbr2sort.size_list / 2)
			rotate(stack_b, 'b');
		else
			rotate_both(stack_a, stack_b);
	}
}

void	sort(t_list **stack_a, t_list **stack_b, t_nbr_info nbr2sort, t_nbr_info target)
{
	ab_top(stack_a, stack_b, nbr2sort, target);
	if ((*stack_a)->content == nbr2sort.content && (*stack_b)->content != target.content)
		b_top(stack_b, target);
	else if ((*stack_b)->content == target.content && (*stack_a)->content != nbr2sort.content)
		a_top(stack_a, nbr2sort);
	push(stack_b, stack_a, 'b');
}
