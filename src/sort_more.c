/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:53 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/08 12:42:07 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//se o numero em a estiver fora dos extremos de b usa o max de b para calcular 
int	min_max(t_list *stack_b, t_info info_a)
{
	t_info	info_b;
	int		target;

	target = find_max(stack_b);
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
	target = find_min(stack_b);
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

t_info	find_target_in_b(t_list *stack_b, int nbr)
{
	t_list	*temp_b;
	t_info	target;

	temp_b = stack_b;
	if (nbr > find_max(stack_b) || nbr < find_min(stack_b))
	{
		target.content = find_max(stack_b);
		target.rotations = check_position(stack_b, target.content);
		return (target);
	}
	else
		target.content = find_min(stack_b);
	while (temp_b != NULL)
	{
		if (nbr > temp_b->content)
		{
			if (target.content < temp_b->content)
				target.content = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	target.rotations = check_position(stack_b, target.content);
	return (target);
}

//calcular qual o numero em a que custa menos movimentos para passar para b
t_info	find_nbr2move(t_list *stack_a, t_list *stack_b, t_info info_a)
{
	t_list	*temp_a;
	t_info	nbr2move;
	int		moves;
	int		cheaper_nbr;

	cheaper_nbr = 0;
	temp_a = stack_a;
	while (temp_a != NULL)
	{
		if (temp_a->content > find_max(stack_b)
			|| temp_a->content < find_min(stack_b))
			moves = min_max(stack_b, info_a);
		else if (temp_a->content < find_max(stack_b)
			&& temp_a->content > find_min(stack_b))
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

void	sort_more(t_list **stack_a, t_list **stack_b)
{
	t_info	info_a;
	t_info	nbr2sort;
	t_info	target;

	push(stack_b, stack_a, 'b');
	push(stack_b, stack_a, 'b');
	info_a.size = ft_lstsize(*stack_a);
	info_a.rotations = 0;
	while (info_a.size > 3)
	{
		nbr2sort = find_nbr2move(*stack_a, *stack_b, info_a);
		nbr2sort.size = ft_lstsize(*stack_a);
		target = find_target_in_b(*stack_b, nbr2sort.content);
		target.size = ft_lstsize(*stack_b);
		srt_stacks(stack_a, stack_b, nbr2sort, target);
		info_a.size = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	put_all_a(stack_a, stack_b);
	rotating_a(stack_a);
}
