/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:01:14 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:04:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int						i;
	unsigned long long int	res;

	i = 0;
	res = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] < 48 || s[i] > 57)
		return (-1);
	while (s[i])
	{
		if (s[i] > 47 && s[i] < 58)
		{
			res = res * 10 + s[i] - 48;
			i++;
		}
		else
			return (-1);
	}
	if (res > INT64_MAX)
		return (-1);
	return ((int)res);
}
