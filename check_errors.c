/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:39:57 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/01 19:10:54 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_integer_limits(long content)
{
	if (content < INT_MIN || content > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_duplicates(t_list *stack)
{
	t_list	*head;
	t_list	*checker;

	head = stack;
	while (stack)
	{
		checker = stack->next;
		while (checker)
		{
			if (stack->content == checker->content)
				return (EXIT_FAILURE);
			checker = checker->next;
		}
		stack = stack->next;
	}
	return (EXIT_SUCCESS);
}

int	check_av(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (nbr[i] >= '0' && nbr[i] <= '9')
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	checker_and_fill(char *nbr, t_list **stack_a)
{
	if (check_av(nbr))
		free_list(stack_a, 1);
	ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(nbr)));
	if (check_integer_limits(ft_atoi(nbr)))
		free_list(stack_a, 1);
	if (check_duplicates(*stack_a))
		free_list(stack_a, 1);
	return (0);
}
