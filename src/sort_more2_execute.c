/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more2_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:47 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/07 16:47:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_top(t_list **stack_a, t_info nbr2sort)
{
	while ((*stack_a)->content != nbr2sort.content)
	{
		if (nbr2sort.rotations > nbr2sort.size / 2)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
}

void	b_top(t_list **stack_b, t_info target)
{
	while ((*stack_b)->content != target.content)
	{
		if (target.rotations > target.size / 2)
			reverse_rotate(stack_b, 'b');
		else
			rotate(stack_b, 'b');
	}
}

void	ab_top(t_list **st_a, t_list **st_b, t_info nbr2sort, t_info target)
{
	while ((*st_a)->content != nbr2sort.content
		&& (*st_b)->content != target.content)
	{
		if (nbr2sort.rotations > nbr2sort.size / 2
			&& target.rotations > target.size / 2)
			reverse_rotate_both(st_a, st_b);
		else if (nbr2sort.rotations < nbr2sort.size / 2
			&& target.rotations > target.size / 2)
			rotate(st_a, 'a');
		else if (target.rotations < target.size / 2
			&& nbr2sort.rotations > nbr2sort.size / 2)
			rotate(st_b, 'b');
		else
			rotate_both(st_a, st_b);
	}
}

void	srt_stacks(t_list **st_a, t_list **st_b, t_info nbr2srt, t_info tgt)
{
	ab_top(st_a, st_b, nbr2srt, tgt);
	if ((*st_a)->content == nbr2srt.content
		&& (*st_b)->content != tgt.content)
		b_top(st_b, tgt);
	else if ((*st_b)->content == tgt.content
		&& (*st_a)->content != nbr2srt.content)
		a_top(st_a, nbr2srt);
	push(st_b, st_a, 'b');
}
