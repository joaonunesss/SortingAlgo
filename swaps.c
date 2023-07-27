/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:25:15 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/24 16:52:32 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack_a, char c)
{
	int	temp;
	
	if (!*stack_a || !(*stack_a)->next)
		exit_error(stack_a);
	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, '\0');
	swap(stack_b, '\0');
	ft_printf("ss\n");
}

void	push(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*temp;
	t_list	*top_b;

	if (!(*stack_b))
		exit_error(stack_a);
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, top_b);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

void	rotate(t_list **stack_a, char c)
{
	t_list	*last;
	t_list	*top;

	if (!*stack_a || !(*stack_a)->next)
		exit_error(stack_a);
	top = *stack_a;
	*stack_a = (*stack_a)->next;
	last = ft_lstlast(*stack_a);
	last->next = top;
	top->next = NULL;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}
