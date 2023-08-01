/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:33 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/01 15:58:20 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_max(t_list *stack_b, t_info info_a)
{
	t_info	info_b;
	int		target;

	target = max(stack_b);
	info_b.size = ft_lstsize(stack_b);
	info_b.rotations = check_position(stack_b, target);
	return (mv_calcs(info_a, info_b));
}

int	btw_min_max(t_list *stack_b, int content_a, t_info info_a)
{
	t_list		*temp_b;
	t_info		info_b;
	int			target;

	temp_b = stack_b;
	target = min(stack_b);
	info_b.size = ft_lstsize(stack_b);
	while (temp_b != NULL)
	{
		if (content_a > temp_b->content)
		{
			if (target < temp_b->content)
				target = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	info_b.rotations = check_position(stack_b, target);
	return (mv_calcs(info_a, info_b));
}

t_info	find_nbr2move(t_list *stack_a, t_list *stack_b, t_info info_a)
{
	t_list		*temp_a;
	t_info	nbr2move;
	int			moves;
	int			cheaper_nbr;

	cheaper_nbr = 0;
	temp_a = stack_a;
	info_a.rotations = 0;
	while (temp_a != NULL)
	{
		if (temp_a->content > max(stack_b) || temp_a->content < min(stack_b))
			moves = min_max(stack_b, info_a);
		else if (temp_a->content < max(stack_b) && temp_a->content > min(stack_b))
			moves = btw_min_max(stack_b, temp_a->content, info_a);
		if (cheaper_nbr > moves || info_a.rotations == 0)
		{
			cheaper_nbr = moves;
			nbr2move.rotations = info_a.rotations;
			nbr2move.content = temp_a->content;
		}
		info_a.rotations++;
		temp_a = temp_a->next;
	}
	return (nbr2move);
}

t_info	b_target(t_list *stack_b, int content_a)
{
	t_list		*temp_b;
	t_info	target;

	temp_b = stack_b;
	if (content_a > max(stack_b) || content_a < min(stack_b))
	{
		target.content = max(stack_b);
		target.rotations = check_position(stack_b, target.content);
		return (target);
	}
	else
		target.content = min(stack_b);
	while (temp_b != NULL)
	{
		if (content_a > temp_b->content)
		{
			if (target.content < temp_b->content)
				target.content = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	target.rotations = check_position(stack_b, target.content);
	return (target);
}
