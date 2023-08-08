/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:14:57 by jmarinho          #+#    #+#             */
/*   Updated: 2023/08/03 15:27:01 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (*str != '\0')
	{
		if (*str == c)
			k = 0;
		else if (k == 0 && *str != c)
		{
			i++;
			k = 1;
		}
		str++;
	}
	return (i);
}

static char	*word_len(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *str, char c)
{
	int		k;
	char	**split;

	if (!str)
		return (NULL);
	while (*str == c && *str != '\0')
		str++;
	split = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (split == NULL)
		return (NULL);
	k = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			split[k++] = word_len((char *)str, c);
			while (*str != c && *str != '\0')
				str++;
		}
		else
			str++;
	}
	split[k] = 0;
	return (split);
}
