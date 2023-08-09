/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:27 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/09 13:25:26 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	move_calc_aux(int b, int a)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int	aux_for_lines(t_info *info_a, t_info *info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a->rotations > info_a->size / 2)
		nbr_m = info_a->size - info_a->rotations;
	else if (info_b->rotations > info_a->size / 2)
		nbr_m = info_b->size - info_b->rotations;
	else
		nbr_m = move_calc_aux(info_b->rotations, info_a->rotations);
	return (nbr_m);
}

int	move_calcs(t_info info_a, t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.rotations != 0 && info_b.rotations != 0)
	{
		if (info_a.rotations >= info_a.size / 2
			&& info_b.rotations >= info_b.size / 2)
			nbr_m = move_calc_aux(info_b.size - info_b.rotations,
					info_a.size - info_a.rotations);
		else if (info_a.rotations > info_a.size / 2
			&& info_b.rotations < info_b.size / 2)
			nbr_m = (info_a.size - info_a.rotations) + info_b.rotations;
		else if (info_a.rotations < info_a.size / 2
			&& info_b.rotations > info_b.size / 2)
			nbr_m = (info_b.size - info_b.rotations) + info_a.rotations;
		else
			nbr_m = move_calc_aux(info_b.rotations, info_a.rotations);
	}
	else
		nbr_m = aux_for_lines(&info_a, &info_b);
	return (++nbr_m);
}
