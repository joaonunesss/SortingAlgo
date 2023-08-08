/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:02:48 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/08 13:12:53 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	roulette(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (check_sort(*stack_a))
	{
		size = ft_lstsize(*stack_a);
		if (size == 2)
			sort_two(stack_a);
		else if (size == 3)
			sort_three(stack_a);
		else if (size == 4)
			sort_four(stack_a, stack_b);
		else if (size == 5)
			sort_five(stack_a, stack_b);
		else
			sort_more(stack_a, stack_b);
	}
}

void	if_ac_2(t_list *stack_a, t_list *stack_b, char **av, int ac)
{
	av = ft_split(av[1], ' ');
	if (!av[0])
		free_array(av, 1);
	check_av(av, 0);
	stack_a = stack_init(av, 0);
	free_array(av, 0);
	check_integer_limits(stack_a);
	check_duplicates(stack_a);
	if (ac >= 2)
		roulette(&stack_a, &stack_b);
	free_list(&stack_a, 0);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || av[1][0] == '\0')
		return (EXIT_FAILURE);
	else if (av[1][0] == ' ')
		exit_error();
	else if (ac == 2 && ft_strchr(av[1], ' '))
		if_ac_2(stack_a, stack_b, av, ac);
	else
	{
		check_av(av, 1);
		stack_a = stack_init(av, 1);
		check_integer_limits(stack_a);
		check_duplicates(stack_a);
		if (ac >= 2)
			roulette(&stack_a, &stack_b);
		free_list(&stack_a, 0);
	}
}
