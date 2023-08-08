/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:52:18 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/08 13:20:52 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_list *list)
{
	int	max;

	max = list->content;
	while (list != NULL)
	{
		if (list->content > max)
			max = list->content;
		list = list->next;
	}
	return (max);
}

int	find_min(t_list *list)
{
	int	min;

	min = list->content;
	while (list != NULL)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	return (min);
}

int	ft_lstsize(t_list *stack_a)
{
	int	i;

	i = 0;
	if (stack_a == NULL)
		return (0);
	else
	{
		while (stack_a != NULL)
		{
			i++;
			stack_a = stack_a->next;
		}
		return (i);
	}
}

t_list	*stack_init(char **av, int flag)
{
	t_list	*stack_a;
	t_list	*head;
	int		i;

	i = 1;
	if (flag == 0)
		i = flag;
	stack_a = NULL;
	head = NULL;
	stack_a = ft_lstnew(ft_atoi(av[i]));
	i++;
	head = stack_a;
	while (av[i])
	{
		stack_a->next = ft_lstnew(ft_atoi(av[i]));
		stack_a = stack_a->next;
		i++;
	}
	return (head);
}
