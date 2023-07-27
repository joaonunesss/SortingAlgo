/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:52:18 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/27 16:19:00 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list *list)
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

int	min(t_list *list)
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

int	check_position(t_list *list, int target)
{
	int	i;

	i = 0;
	while (list->content != target)
	{
		i++;
		list = list->next;
	}
	return (i);
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