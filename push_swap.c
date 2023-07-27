/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:48 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/27 16:57:29 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_av(char *av[], int *ac)
{
	char	**temp;
	int		i;
	int		j;

	temp = ft_split(av[1], ' ');
	i = 0;
	j = 1;
	while (temp[i])
	{
		av[j] = temp[i];
		i++;
		j++;
	}
	*ac = j;
	av[j] = NULL;
	return (av);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;
	int		i;
	int 	size;

	if (ac < 2)
		return (EXIT_FAILURE);
	else if (ac == 2)
		av = split_av(av, &ac);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	temp = NULL;
	while (i < ac)
	{
		checker_and_fill(av[i], &stack_a);
		i++;
	}
	size = ft_lstsize(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_more(&stack_a, &stack_b);
	printlinkedlist(stack_a);
	freelinkedlist(stack_a);
}
