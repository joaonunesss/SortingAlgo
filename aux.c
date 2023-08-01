/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:20:06 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/01 19:07:20 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error()
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_array(char *array[])
{
	int	i;

	i = 1;
	while (array[i])
		free(array[i++]);
	free(array);
	exit_error();
}

void	free_list(t_list **lst, int flag)
{
	t_list	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	if (flag == 1)
		exit_error();
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

int	ft_min_index(t_list **stack_a)
{
	t_list	*temp;
	int		index;
	int		min;
	int		i;

	i = 1;
	index = 1;
	temp = *stack_a;
	min = (*stack_a)->content;
	while (temp->content)
	{
		if (temp->content < min)
		{
			min = temp->content;
			index = i;
		}
		if (!temp->next)
			break ;
		temp = temp->next;
		i++;
	}
	return (index);
}
