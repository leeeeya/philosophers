/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:54:08 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:49 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	t_time	n;

	if (gettimeofday(&n, NULL) != 0)
		return (-1);
	return ((long int)(n.tv_sec * 1000 + n.tv_usec / 1000));
}

int	ft_usleep(long int ms)
{
	long int	start_action;
	long int	now;
	long int	s;

	start_action = get_time();
	if (start_action < 0)
		return (-1);
	while (1)
	{
		now = get_time();
		s = now - start_action;
		if (s < (long int)ms)
		{
			if (usleep(10) != 0)
				return (-1);
			continue ;
		}
		break ;
	}
	return (0);
}
