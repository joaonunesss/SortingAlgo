/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:27 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/01 15:15:00 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mv_calc1(t_info info_a, t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if ((info_a.size - info_a.rotations) < 
		(info_b.size - info_b.rotations))
		nbr_m = info_b.size - info_b.rotations;
	else if ((info_b.size - info_b.rotations) < 
		(info_a.size - info_a.rotations))
		nbr_m = info_a.size - info_a.rotations;
	else
		nbr_m = info_a.size - info_a.rotations;
	return (nbr_m);
}

int	mv_calc2(int rotations_a, int rotations_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (rotations_a < rotations_b)
		nbr_m = rotations_b;
	else if (rotations_a > rotations_b)
		nbr_m = rotations_a;
	else
		nbr_m = rotations_a;
	return (nbr_m);
}

int	mv_calc3(t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_b.rotations > info_b.size / 2)
		nbr_m = (info_b.size - info_b.rotations);
	else
		nbr_m = info_b.rotations;
	return (nbr_m);
}

int	mv_calc4(t_info info_a)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.rotations > info_a.size / 2)
		nbr_m = (info_a.size - info_a.rotations);
	else
		nbr_m = info_a.rotations;
	return (nbr_m);
}

int	mv_calcs(t_info info_a, t_info info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.rotations > 0 && info_b.rotations > 0)
	{
		if (info_a.rotations >= info_a.size / 2
			&& info_b.rotations >= info_b.size / 2)
			nbr_m = mv_calc1(info_a, info_b);
		else if (info_a.rotations > info_a.size / 2
			&& info_b.rotations < info_b.size / 2)
			nbr_m = (info_a.size - info_a.rotations) + info_b.rotations;
		else if (info_b.rotations > info_b.size / 2
			&& info_a.rotations < info_a.size / 2)
			nbr_m = (info_b.size - info_b.rotations) + info_a.rotations ;
		else if (info_a.rotations <= info_a.size / 2
			&& info_b.rotations <= info_b.size / 2)
			nbr_m = mv_calc2(info_a.rotations, info_b.rotations);
	}
	if (info_a.rotations == 0)
		nbr_m = mv_calc3(info_b);
	else if (info_b.rotations == 0)
		nbr_m = mv_calc4(info_a);
	return (++nbr_m);
}
