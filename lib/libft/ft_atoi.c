/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:57:19 by jmarinho          #+#    #+#             */
/*   Updated: 2023/07/11 14:37:40 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_aux(int i, const char *str)
{
	long	atoi;

	atoi = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		atoi = atoi * 10 + str[i] - 48;
		i++;
	}
	return (atoi);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		signal;
	long	result;

	i = 0;
	signal = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signal = -1;
		i++;
	}
	result = ft_atoi_aux(i, str);
	return (result * signal);
}
