/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:39:57 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/03 15:12:14 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_integer_limits(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		if ((temp->content > INT_MAX || temp->content < INT_MIN))
			free_list(&stack_a, 1);
		temp = temp->next;
	}
}

void	check_duplicates(t_list *stack)
{
	t_list	*head;
	t_list	*temp;

	head = stack;
	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->content == stack->content)
				free_list(&head, 1);
			temp = temp->next;
		}
		stack = stack->next;
	}
}

void	check_av(char **av, int flag)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (!flag)
		i = 0;
	while (av[i])
	{
		k = 0;
		if (av[i][k] == '-' && av[i][k + 1])
			k++;
		while (av[i][k])
		{
			if (av[i][k] >= '0' && av[i][k] <= '9')
				k++;
			else
			{
				if (flag == 0)
					free_array(av, 0);
				exit_error();
			}
		}
		i++;
	}
}

int	check_sort(t_list *stack_a)
{
	if (ft_lstsize (stack_a) == 1)
		return (EXIT_SUCCESS);
	while ((stack_a->content <= stack_a->next->content) && stack_a != NULL)
	{
		stack_a = stack_a->next;
		if (stack_a->next == NULL)
			break ;
	}
	if (stack_a->next == NULL)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
