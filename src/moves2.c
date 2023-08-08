/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:59:06 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/07 16:47:39 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, '\0');
	rotate(stack_b, '\0');
	ft_printf("rr\n");
}

void	reverse_rotate(t_list **stack_a, char c)
{
	t_list	*last;
	t_list	*temp;

	if (!*stack_a || !(*stack_a)->next)
		free_list(stack_a, 1);
	last = ft_lstlast(*stack_a);
	temp = *stack_a;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, '\0');
	reverse_rotate(stack_b, '\0');
	ft_printf("rrr\n");
}
