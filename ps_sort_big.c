/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:53 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/27 17:20:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotating_a(t_list **stack_a)
{
	int	size;
	int	position;

	position = check_position(*stack_a, min(*stack_a));
	size = ft_lstsize(*stack_a);
	while ((*stack_a)->content != min(*stack_a))
	{
		if (position > size / 2)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
}

void	sort_more(t_list **stack_a, t_list **stack_b)
{
	t_info_a	info_a;
	t_nbr_info	nbr2sort;
	t_nbr_info	target;

	if (!check_sort(*stack_a))
		return ;
	push(stack_b, stack_a, 'b');
	push(stack_b, stack_a, 'b');
	info_a.size_a = ft_lstsize(*stack_a);
	while (info_a.size_a > 3)
	{
		nbr2sort = a_nbr2move(*stack_a, *stack_b, info_a);
		nbr2sort.size_list = ft_lstsize(*stack_a);
		target = b_target(*stack_b, nbr2sort.content);
		target.size_list = ft_lstsize(*stack_b);
		sort(stack_a, stack_b, nbr2sort, target);
		info_a.size_a = ft_lstsize(*stack_a);
	}
	sort_three(stack_a);
	put_all_a(stack_a, stack_b);
	rotating_a(stack_a);
}
