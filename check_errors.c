/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:39:57 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/24 12:13:04 by jmarinho         ###   ########.fr       */
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

int	check_av(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	checker_and_fill(char *str, t_list **stack_a)
{
	if (check_av(str))
		exit_error(stack_a);
	ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(str)));
	if (check_integer_limits(ft_atoi(str)))
		exit_error(stack_a);
	if (check_duplicates(*stack_a))
		exit_error(stack_a);
}
